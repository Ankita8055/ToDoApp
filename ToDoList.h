#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "Task.h"

class ToDoList {
private:
    std::vector<Task> tasks;
    int nextId;

    void saveTasksToFile();
    void loadTasksFromFile();

public:
    ToDoList();
    void addTask(const std::string& description);
    void viewTasks() const;
    void deleteTask(int id);
    void markTaskCompleted(int id);
};

#endif // TODOLIST_H

