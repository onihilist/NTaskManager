//
// Created by onihilist on 23/07/2025.
//

#include "../includes/LegacyTask.h++"

#include <algorithm>
#include <array>
#include <regex>
#include <sstream>

LegacyTask::LegacyTask(std::string imageName, int pID, std::string sessionName, int sessionNumber, int memoryUsage)
    : imageName(imageName), pID(pID), sessionName(sessionName), sessionNumber(sessionNumber), memoryUsage(memoryUsage) {}

LegacyTask::~LegacyTask(){std::cout<< "~LegacyTask() instance destoyed" << std::endl;}

std::string LegacyTask::exec_c_array(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        std::cout << "popen() failed" << std::endl;
    }

    while (fgets(buffer.data(), buffer.size(), pipe)) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

std::vector<LegacyTask> LegacyTask::split_task_c_array(const std::string& raw) {
    std::vector<LegacyTask> legacyTasksList;
    std::istringstream stream(raw);
    std::string line;
    int lineCount = 0;

    while (std::getline(stream, line)) {
        if (++lineCount <= 3 || line.empty()) continue;

        std::smatch match;
        std::regex pattern(R"((.+?)\s+(\d+)\s+(\S+)\s+(\d+)\s+([\d\s\u00A0]+) Ko)");

        if (std::regex_match(line, match, pattern)) {
            std::string imageName = match[1].str();
            int pid = std::stoi(match[2].str());
            std::string sessionName = match[3].str();
            int sessionNumber = std::stoi(match[4].str());

            std::string memStr = match[5].str();
            memStr.erase(remove_if(memStr.begin(), memStr.end(),
                                   [](char c) { return !isdigit(c); }), memStr.end());

            int memKB = std::stoi(memStr);
            legacyTasksList.emplace_back(imageName, pid, sessionName, sessionNumber, memKB);
        }
    }

    return legacyTasksList;
}

std::string LegacyTask::getImageName() const {
    return imageName;
}

int LegacyTask::getPID() const {
    return pID;
}

std::string LegacyTask::getSessionName() const {
    return sessionName;
}

int LegacyTask::getSessionNumber() const {
    return sessionNumber;
}

int LegacyTask::getMemoryUsage() const {
    return memoryUsage;
}