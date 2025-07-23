//
// Created by onihilist on 23/07/2025.
//

#ifndef LEGACYTASK_H
#define LEGACYTASK_H
#include <iostream>
#include <string>
#include <vector>

class LegacyTask {

    private:
        std::string imageName;
        int pID;
        std::string sessionName;
        int sessionNumber;
        int memoryUsage;

    public:
        LegacyTask(std::string imageName, int pID, std::string sessionName, int sessionNumber, int memoryUsage);
        ~LegacyTask();

        static std::string exec_c_array(const char* cmd);
        static std::vector<LegacyTask> split_task_c_array(const std::string& s);

        void setImageName(std::string imageName);
        void setPID(int pID);
        void setSessionName(std::string sessionName);
        void setSessionNumber(int sessionNumber);
        void setMemoryUsage(int memoryUsage);

        std::string getImageName() const;
        int getPID() const;
        std::string getSessionName() const;
        int getSessionNumber() const;
        int getMemoryUsage() const;

};

#endif //LEGACYTASK_H
