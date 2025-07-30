
#include "includes/DashboardManager.h++"

int main() {
    /*std::string resultString = LegacyTask::exec_c_array("tasklist");
    std::vector<LegacyTask> legacyTasks = LegacyTask::split_task_c_array(resultString);
    std::cout << resultString << std::endl << "=================" << std::endl;
    std::cout << legacyTasks[2].getImageName() << std::endl;*/

    DashboardManager dashboard;
    dashboard.run();

    return 0;
}
