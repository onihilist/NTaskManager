#include "../includes/ProcessInfo.h++"

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include <iomanip>

ProcessInfo::ProcessInfo() {}

ULONGLONG FileTimeToUInt64(const FILETIME& ft) {
    ULARGE_INTEGER uli;
    uli.LowPart = ft.dwLowDateTime;
    uli.HighPart = ft.dwHighDateTime;
    return uli.QuadPart;
}

bool GetProcessCPUTime(HANDLE hProcess, ULONGLONG& totalCPUTime) {
    FILETIME ftCreation, ftExit, ftKernel, ftUser;
    if (!GetProcessTimes(hProcess, &ftCreation, &ftExit, &ftKernel, &ftUser)) {
        return false;
    }
    totalCPUTime = FileTimeToUInt64(ftKernel) + FileTimeToUInt64(ftUser);
    return true;
}

std::string FormatMemory(SIZE_T bytes) {
    double mb = bytes / 1024.0 / 1024.0;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1);
    if (mb >= 1024.0) {
        double gb = mb / 1024.0;
        ss << gb << " GB";
    }
    else {
        ss << mb << " MB";
    }
    return ss.str();
}

std::vector<std::vector<std::string>> ProcessInfo::GetProcessesTable() {
    std::vector<std::vector<std::string>> rows;
    rows.push_back({ "PID", "Name", "CPU%", "Memory" });

    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE) {
        return rows;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(hSnap, &pe32)) {
        CloseHandle(hSnap);
        return rows;
    }

    struct CpuMeasure {
        DWORD pid;
        ULONGLONG cpuTime;
    };
    std::vector<CpuMeasure> cpuStartTimes;
    std::vector<PROCESSENTRY32> procEntries;

    do {
        procEntries.push_back(pe32);
    } while (Process32Next(hSnap, &pe32));
    CloseHandle(hSnap);

    for (const auto& pe : procEntries) {
        HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe.th32ProcessID);
        if (hProc) {
            ULONGLONG cpuTime;
            if (GetProcessCPUTime(hProc, cpuTime)) {
                cpuStartTimes.push_back({ pe.th32ProcessID, cpuTime });
            }
            else {
                cpuStartTimes.push_back({ pe.th32ProcessID, 0 });
            }
            CloseHandle(hProc);
        }
        else {
            cpuStartTimes.push_back({ pe.th32ProcessID, 0 });
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    int numCPUs = sysInfo.dwNumberOfProcessors;

    for (size_t i = 0; i < procEntries.size(); i++) {
        DWORD pid = procEntries[i].th32ProcessID;
        std::string name = procEntries[i].szExeFile;

        HANDLE hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
        ULONGLONG cpuTimeEnd = 0;
        SIZE_T memUsage = 0;

        if (hProc) {
            GetProcessCPUTime(hProc, cpuTimeEnd);

            PROCESS_MEMORY_COUNTERS pmc;
            if (GetProcessMemoryInfo(hProc, &pmc, sizeof(pmc))) {
                memUsage = pmc.WorkingSetSize;
            }
            CloseHandle(hProc);
        }

        ULONGLONG cpuTimeStart = 0;
        for (const auto& c : cpuStartTimes) {
            if (c.pid == pid) {
                cpuTimeStart = c.cpuTime;
                break;
            }
        }

        ULONGLONG delta = (cpuTimeEnd > cpuTimeStart) ? (cpuTimeEnd - cpuTimeStart) : 0;
        double cpuPercent = (double)delta / 10000000.0 / numCPUs * 100.0;
        int cpuPercentInt = static_cast<int>(cpuPercent + 0.5);

        rows.push_back({ std::to_string(pid), name, std::to_string(cpuPercentInt), FormatMemory(memUsage) });
    }

    return rows;
}
