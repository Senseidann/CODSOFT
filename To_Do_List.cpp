#include <iostream>
#include <string>
#include <vector>

struct Task{
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks, const std::string& description){
    tasks.push_back({description, false});
    std::cout << "Task added: " << description << std::endl;
}

void viewTasks(const std::vector<Task>& tasks){
    if (tasks.empty()){
        std::cout << "No tasks in the list." << std::endl;
        return;
    }
    
    std::cout << "Tasks:\n";
    
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << "[" << (tasks[i].completed ? "X" : " ") << "] ";
        std::cout << tasks[i].description << std::endl;
    }
}

void markCompleted(std::vector<Task>& tasks, int taskIndex){
    if(taskIndex >= 1 && taskIndex <= tasks.size()){
        tasks[taskIndex - 1].completed = true;
        std::cout << "Task " << taskIndex << " marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks, int taskIndex){
    if(taskIndex >= 1 && taskIndex <= tasks.size()){
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task " << taskIndex << " removed." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}
int main() {
    std::vector<Tasks> tasks;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume newline character

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                AddTask(tasks, description);
                break;
            }
            case 2:
                ViewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                CompleteTask(tasks, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                RemoveTask(tasks, taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}