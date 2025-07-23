//
// Created by onihilist on 23/07/2025.
//

#ifndef LEGACYTASK_H
#define LEGACYTASK_H
#include <iostream>
#include <string>

class LegacyTask {

    private:
        std::string imageName;
        int pID;
        std::string sessionName;
        int sessionNumber;
        int memoryUsage;

    public:
        LegacyTask(std::string imageName, std::string sessionName, int sessionNumber, int memoryUsage);
        ~LegacyTask();

        static std::string exec_c_array(const char* cmd);

        void setImageName(std::string imageName);
        void setPID(int pID);
        void setSessionName(std::string sessionName);
        void setSessionNumber(int sessionNumber);
        void setMemoryUsage(int memoryUsage);

        std::string getImageName();
        int getPID();
        std::string getSessionName();
        int getSessionNumber();
        int getMemoryUsage();

};

#endif //LEGACYTASK_H
