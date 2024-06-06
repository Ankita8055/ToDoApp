#include "ToDoList.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "To-Do List Application\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Delete Task\n";
    std::cout << "4. Mark Task Completed\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ToDoList toDoList;
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        while (std::cin.fail() || choice < 1 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 5: ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::string description;
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2: {
                toDoList.viewTasks();
                break;
            }
            case 3: {
                std::cout << "Enter task ID to delete: ";
                int id;
                std::cin >> id;
                toDoList.deleteTask(id);
                break;
            }
            case 4: {
                std::cout << "Enter task ID to mark as completed: ";
                int id;
                std::cin >> id;
                toDoList.markTaskCompleted(id);
                break;
            }
            case 5: {
                std::cout << "Exiting application...\n";
                break;
            }
        }
        std::cout << "\n";
    } while (choice != 5);

    return 0;
}

