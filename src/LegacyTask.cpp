//
// Created by onihilist on 23/07/2025.
//

#include "../includes/LegacyTask.h++"

#include <array>

LegacyTask::LegacyTask(std::string imageName, std::string sessionName, int sessionNumber, int memoryUsage)
    : imageName(imageName), sessionName(sessionName), sessionNumber(sessionNumber), memoryUsage(memoryUsage) {}

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