#include <bits/stdc++.h>
using namespace std;
// --- Observer Pattern for Notification ---
class Observer {
public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() = default;
};
class Subject {
    vector<Observer*> observers;
public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void detach(Observer* obs) {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notify(const string& message) {
        for (auto obs : observers) obs->update(message);
    }
};
// --- Strategy Pattern for Sorting Tasks ---
class SortStrategy {
public:
    virtual void sort(vector<shared_ptr<class Task>>& tasks) = 0;
    virtual ~SortStrategy() = default;
};
class SortByDueDate : public SortStrategy {
public:
    void sort(vector<shared_ptr<class Task>>& tasks) override;
};
class SortByPriority : public SortStrategy {
public:
    void sort(vector<shared_ptr<class Task>>& tasks) override;
};
// --- Command Pattern for Undo/Redo ---
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};
// --- Factory Pattern for Task Creation ---
class TaskFactory {
public:
    virtual shared_ptr<class Task> createTask(const string& title, const string& desc, int priority) = 0;
    virtual ~TaskFactory() = default;
};
class SimpleTaskFactory : public TaskFactory {
public:
    shared_ptr<class Task> createTask(const string& title, const string& desc, int priority) override;
};
// --- Task Entity ---
class Task {
protected:
    int id;
    string title;
    string description;
    int priority;
    string dueDate;
    bool completed;
public:
    Task(int id, const string& title, const string& desc, int priority)
        : id(id), title(title), description(desc), priority(priority), completed(false) {}
    virtual ~Task() = default;
    virtual void display() const;
    int getId() const { return id; }
    int getPriority() const { return priority; }
    string getDueDate() const { return dueDate; }
    void setDueDate(const string& date) { dueDate = date; }
    void markCompleted() { completed = true; }
    bool isCompleted() const { return completed; }
};
// --- Decorator Pattern for Task Labels ---
class TaskDecorator : public Task {
protected:
    shared_ptr<Task> task;
public:
    TaskDecorator(shared_ptr<Task> t) : Task(*t), task(t) {}
    void display() const override { task->display(); }
};
class LabeledTask : public TaskDecorator {
    string label;
public:
    LabeledTask(shared_ptr<Task> t, const string& lbl) : TaskDecorator(t), label(lbl) {}
    void display() const override {
        task->display();
        cout << "Label: " << label << endl;
    }
};
// --- Singleton Pattern for TaskManager ---
class TaskManager : public Subject {
    vector<shared_ptr<Task>> tasks;
    unique_ptr<SortStrategy> sortStrategy;
    static TaskManager* instance;
    TaskManager() = default;
public:
    static TaskManager* getInstance() {
        if (!instance) instance = new TaskManager();
        return instance;
    }
    void addTask(shared_ptr<Task> task) { tasks.push_back(task); notify("Task added"); }
    void removeTask(int id) {
        tasks.erase(remove_if(tasks.begin(), tasks.end(),
            [id](const shared_ptr<Task>& t){ return t->getId() == id; }), tasks.end());
        notify("Task removed");
    }
    void setSortStrategy(unique_ptr<SortStrategy> strategy) { sortStrategy = move(strategy); }
    void sortTasks() { if (sortStrategy) sortStrategy->sort(tasks); }
    vector<shared_ptr<Task>>& getTasks() { return tasks; }
};
TaskManager* TaskManager::instance = nullptr;
// --- Implementations ---
void SortByDueDate::sort(vector<shared_ptr<Task>>& tasks) {
    std::sort(tasks.begin(), tasks.end(), [](const shared_ptr<Task>& a, const shared_ptr<Task>& b) {
        return a->getDueDate() < b->getDueDate();
    });
}
void SortByPriority::sort(vector<shared_ptr<Task>>& tasks) {
    std::sort(tasks.begin(), tasks.end(), [](const shared_ptr<Task>& a, const shared_ptr<Task>& b) {
        return a->getPriority() > b->getPriority();
    });
}
shared_ptr<Task> SimpleTaskFactory::createTask(const string& title, const string& desc, int priority) {
    static int id = 1;
    return make_shared<Task>(id++, title, desc, priority);
}
void Task::display() const {
    cout << "Task #" << id << ": " << title << " [" << (completed ? "Done" : "Pending") << "]\n";
    cout << "Priority: " << priority << ", Due: " << dueDate << "\n";
    cout << "Description: " << description << endl;
}
// --- Example Observer ---
class EmailNotifier : public Observer {
public:
    void update(const string& message) override {
        cout << "[EmailNotifier] " << message << endl;
    }
};
int main() {
    // Create TaskManager singleton instance
    TaskManager* manager = TaskManager::getInstance();
    // Attach an observer (EmailNotifier)
    EmailNotifier emailNotifier;
    manager->attach(&emailNotifier);
    // Create a task factory
    SimpleTaskFactory factory;
    // Add some tasks
    auto t1 = factory.createTask("Buy groceries", "Milk, Bread, Eggs", 2);
    t1->setDueDate("2024-06-10");
    manager->addTask(t1);

    auto t2 = factory.createTask("Finish project", "Complete the LLD assignment", 5);
    t2->setDueDate("2024-06-05");
    manager->addTask(t2);

    // Decorate a task with a label
    auto labeled = make_shared<LabeledTask>(t2, "Work");
    manager->addTask(labeled);
    // Display all tasks
    cout << "\nAll Tasks:\n";
    for (auto& task : manager->getTasks()) {
        task->display();
        cout << endl;
    }
    // Sort by due date
    manager->setSortStrategy(make_unique<SortByDueDate>());
    manager->sortTasks();
    cout << "\nTasks Sorted by Due Date:\n";
    for (auto& task : manager->getTasks()) {
        task->display();
        cout << endl;
    }
    // Sort by priority
    manager->setSortStrategy(make_unique<SortByPriority>());
    manager->sortTasks();
    cout << "\nTasks Sorted by Priority:\n";
    for (auto& task : manager->getTasks()) {
        task->display();
        cout << endl;
    }
    // Mark a task as completed
    t1->markCompleted();
    manager->notify("A task was marked as completed.");
    // Remove a task
    manager->removeTask(t2->getId());
    // Display remaining tasks
    cout << "\nRemaining Tasks:\n";
    for (auto& task : manager->getTasks()) {
        task->display();
        cout << endl;
    }
    return 0;
}

// --- MongoDB Schema (Document Model, Extensible) ---
// Users Collection Example Document:
/*
{
    _id: ObjectId("..."),
    username: "john_doe",
    email: "john@example.com"
}
*/

// Tasks Collection Example Document:
/*
{
    _id: ObjectId("..."),
    user_id: ObjectId("..."), // Reference to users._id
    title: "Buy groceries",
    description: "Milk, Bread, Eggs",
    priority: 2,
    due_date: ISODate("2024-06-10T00:00:00Z"),
    completed: false,
    label: "Personal",
    tags: ["shopping", "urgent"], // Extensible array field
    custom_fields: {             // Extensible object for extra attributes
        location: "Supermarket",
        estimated_time: 30
    },
    history: [                   // Embedded history for this task
        {
            action: "created",
            timestamp: ISODate("2024-06-01T10:00:00Z")
        },
        {
            action: "updated",
            timestamp: ISODate("2024-06-02T12:00:00Z")
        }
    ]
}
*/

// NoSQL (MongoDB) allows you to add new fields or arrays to documents at any time, making the schema highly extensible.