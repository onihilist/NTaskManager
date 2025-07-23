#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Task {
private:
    int id;
    std::string title;
    std::string description;
    std::string limitDate;
    std::string status;

public:
    Task(int id, std::string title, std::string description, std::string limitDate, std::string status);
    void display();
    static void display_tasks(std::vector<Task>& tasks);

    static void edit_task(Task& task);

    int getId() const;
    std::string getTitle() const;

    void setId(int newId);
    void setTitle(const std::string& newTitle);
};

#endif // TASK_H
