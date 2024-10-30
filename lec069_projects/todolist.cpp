#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    int id;
    string description;
    bool completed;
};

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (const auto& task : tasks) {
        cout << task.id << ". " << task.description 
             << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
    }
}

void addTask(vector<Task>& tasks, const string& description) {
    int id = tasks.empty() ? 1 : tasks.back().id + 1;
    tasks.push_back({id, description, false});
    cout << "Task added successfully!\n";
}

void completeTask(vector<Task>& tasks, int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            cout << "Task marked as completed!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

void deleteTask(vector<Task>& tasks, int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted successfully!\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

int main() {
    vector<Task> tasks;
    int choice, id;
    string description;

    while (true) {
        cout << "\nTo-Do List Menu:\n"
             << "1. Display Tasks\n"
             << "2. Add Task\n"
             << "3. Complete Task\n"
             << "4. Delete Task\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character after choice input

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 3:
                cout << "Enter task ID to mark as completed: ";
                cin >> id;
                completeTask(tasks, id);
                break;
            case 4:
                cout << "Enter task ID to delete: ";
                cin >> id;
                deleteTask(tasks, id);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
