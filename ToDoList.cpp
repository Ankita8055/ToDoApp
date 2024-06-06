#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

ToDoList::ToDoList() : nextId(1) {
    loadTasksFromFile();
}

void ToDoList::addTask(const std::string& description) {
    Task newTask(nextId++, description);
    tasks.push_back(newTask);
    saveTasksToFile();
}

void ToDoList::viewTasks() const {
    std::cout << "ID\tDescription\t\tCompleted\n";
    for (const auto& task : tasks) {
        std::cout << task.id << "\t" << task.description << "\t\t" << (task.completed ? "Yes" : "No") << "\n";
    }
}

void ToDoList::deleteTask(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
                             [id](const Task& task) { return task.id == id; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        saveTasksToFile();
    } else {
        std::cerr << "Task ID not found.\n";
    }
}

void ToDoList::markTaskCompleted(int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            saveTasksToFile();
            return;
        }
    }
    std::cerr << "Task ID not found.\n";
}

void ToDoList::saveTasksToFile() {
    std::ofstream outFile("tasks.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    for (const auto& task : tasks) {
        outFile << task.id << ";" << task.description << ";" << task.completed << "\n";
    }
    outFile.close();
}

void ToDoList::loadTasksFromFile() {
    std::ifstream inFile("tasks.txt");
    if (!inFile) {
        return;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string token;
        Task task(0, "");
        std::getline(iss, token, ';');
        task.id = std::stoi(token);
        std::getline(iss, token, ';');
        task.description = token;
        std::getline(iss, token, ';');
        task.completed = (token == "1");
        tasks.push_back(task);
        if (task.id >= nextId) {
            nextId = task.id + 1;
        }
    }
    inFile.close();
}

