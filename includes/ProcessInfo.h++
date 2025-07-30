//
// Created by otual on 30/07/2025.
//

#ifndef PROCESSINFO_H
#define PROCESSINFO_H
#include <string>
#include <vector>

class ProcessInfo {
    public:
        ProcessInfo();

        std::vector<std::vector<std::string>> GetProcessesTable();
};

#endif //PROCESSINFO_H
