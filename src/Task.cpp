#include "../includes/Task.h++"
#include <iostream>

Task::Task(int id, std::string title, std::string description, std::string limitDate, std::string status)
    : id(id), title(title), description(description), limitDate(limitDate), status(status) {}

int Task::getId() const {
    return id;
}

std::string Task::getTitle() const {
    return title;
}

void Task::setId(int newId) {
    id = newId;
}

void Task::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Task::display() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Limit Date: " << limitDate << std::endl;
    std::cout << "Status: " << status << std::endl;
}

void Task::displayTasks(std::vector<Task>& tasks) {
    for (Task& t : tasks) {
        t.display();
        std::cout << "-------------------\n";
    }
}

void Task::editTask(Task& task) {
        task.setTitle("ID_" + std::to_string(task.getId()));
}