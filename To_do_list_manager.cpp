#include <iostream>
#include <vector>
#include <string>
#include<conio.h>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter the task description: ";
    cin.ignore(); // To clear the newline character left by previous input
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task \"" << newTask.description << "\" added.\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " - " << (tasks[i].completed ? "Completed" : "Pending") << "\n";
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    size_t taskNum;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNum;

    if (taskNum >= 1 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task \"" << tasks[taskNum - 1].description << "\" marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    size_t taskNum;
    cout << "Enter the task number to remove: ";
    cin >> taskNum;

    if (taskNum >= 1 && taskNum <= tasks.size()) {
        cout << "Task \"" << tasks[taskNum - 1].description << "\" removed.\n";
        tasks.erase(tasks.begin() + taskNum - 1);
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

