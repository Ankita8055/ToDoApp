#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    int id;
    std::string description;
    bool completed;

    Task(int id, const std::string& description, bool completed = false);
};

#endif // TASK_H


