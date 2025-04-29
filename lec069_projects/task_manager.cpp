#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

class TodoManager {
private:
    vector<Task> tasks;
    int nextId;

    void displayTask(const Task& task) {
        cout << "[" << task.id << "] ";
        cout << (task.completed ? "[X] " : "[ ] ");
        cout << task.description << endl;
    }

public:
    TodoManager() : nextId(1) {}

    void addTask(const string& description) {
        tasks.push_back({nextId++, description, false});
        cout << "Task added successfully!" << endl;
    }

    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
            return;
        }

        cout << "Your Tasks:" << endl;
        for (const auto& task : tasks) {
            displayTask(task);
        }
    }

    void editTask(int id, const string& newDescription) {
        auto it = find_if(tasks.begin(), tasks.end(), 
            [id](const Task& t) { return t.id == id; });

        if (it != tasks.end()) {
            it->description = newDescription;
            cout << "Task updated successfully!" << endl;
        } else {
            cout << "Task not found." << endl;
        }
    }

    void deleteTask(int id) {
        auto it = find_if(tasks.begin(), tasks.end(), 
            [id](const Task& t) { return t.id == id; });

        if (it != tasks.end()) {
            tasks.erase(it);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Task not found." << endl;
        }
    }

    void toggleTask(int id) {
        auto it = find_if(tasks.begin(), tasks.end(), 
            [id](const Task& t) { return t.id == id; });

        if (it != tasks.end()) {
            it->completed = !it->completed;
            cout << "Task status updated!" << endl;
            displayTask(*it);
        } else {
            cout << "Task not found." << endl;
        }
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TodoManager manager;
    int choice;
    string input;

    cout << "===== Todo Manager =====" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. List Tasks\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Toggle Task Completion\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                getline(cin, input);
                manager.addTask(input);
                break;
            }
            case 2:
                manager.listTasks();
                break;
            case 3: {
                int id;
                cout << "Enter task ID to edit: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                cout << "Enter new description: ";
                getline(cin, input);
                manager.editTask(id, input);
                break;
            }
            case 4: {
                int id;
                cout << "Enter task ID to delete: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                manager.deleteTask(id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter task ID to toggle completion: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID.\n";
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                manager.toggleTask(id);
                break;
            }
            case 6:
                cout << "Exiting Todo Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
