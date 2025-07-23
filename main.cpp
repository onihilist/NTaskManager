
#include <iostream>
#include <ostream>
//#include <vector>

#include "includes/LegacyTask.h++"
//#include "includes/Task.h++"

int main() {
    //std::vector<Task> tasks = {
    //    {1, "title", "description", "limitDate", "statusmdr"},
    //    {2, "Title", "Desc", "LimitDate", "Status"}
    //};
    //Task::displayTasks(tasks);
    //Task::editTask(tasks[0]);
    //Task::displayTasks(tasks);

    std::string result = LegacyTask::exec_c_array("tasklist");
    std::cout << system("tasklist") << std::endl;
    return 0;
}
