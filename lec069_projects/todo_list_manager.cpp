#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) {
        description = desc;
        isCompleted = false;
    }

    void display(int index) {
        cout << index + 1 << ". [" << (isCompleted ? "✓" : " ") << "] " << description << "\n";
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask() {
        string desc;
        cout << "Enter task description: ";
        getline(cin, desc);
        tasks.push_back(Task(desc));
        cout << "Task added!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found.\n";
            return;
        }
        cout << "\n--- Todo List ---\n";
        for (size_t i = 0; i < tasks.size(); ++i)
            tasks[i].display(i);
    }

    void markCompleted() {
        int index;
        viewTasks();
        cout << "Enter task number to mark as completed: ";
        cin >> index;
        cin.ignore();

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks[index - 1].isCompleted = true;
        cout << "Marked as completed!\n";
    }

    void deleteTask() {
        int index;
        viewTasks();
        cout << "Enter task number to delete: ";
        cin >> index;
        cin.ignore();

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }

        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task deleted.\n";
    }
};

int main() {
    TodoList todo;
    int choice;

    while (true) {
        cout << "\n=== Todo List Menu ===\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark as Completed\n4. Delete Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1: todo.addTask(); break;
            case 2: todo.viewTasks(); break;
            case 3: todo.markCompleted(); break;
            case 4: todo.deleteTask(); break;
            case 5: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
