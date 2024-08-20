#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Job {
public:
    string title;
    string description;
    string company;

    Job(const string& t, const string& d, const string& c) : title(t), description(d), company(c) {}

    void display() const {
        cout << "Title: " << title << "\n";
        cout << "Description: " << description << "\n";
        cout << "Company: " << company << "\n";
    }
};

class JobPortal {
private:
    vector<Job> jobs;

public:
    void addJob(const string& title, const string& description, const string& company) {
        jobs.emplace_back(title, description, company);
    }

    void listJobs() const {
        if (jobs.empty()) {
            cout << "No jobs available.\n";
            return;
        }

        for (size_t i = 0; i < jobs.size(); ++i) {
            cout << "Job ID: " << i + 1 << "\n";
            jobs[i].display();
            cout << "--------------------------------------\n";
        }
    }

    void applyForJob(size_t jobId) const {
        if (jobId < 1 || jobId > jobs.size()) {
            cout << "Invalid job ID.\n";
            return;
        }

        cout << "Applying for job:\n";
        jobs[jobId - 1].display();
        cout << "Application submitted.\n";
    }
};

int main() {
    JobPortal portal;
    int choice;
    string title, description, company;

    do {
        cout << "1. Add Job\n";
        cout << "2. List Jobs\n";
        cout << "3. Apply for Job\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore newline character left in buffer

        switch (choice) {
            case 1:
                cout << "Enter job title: ";
                getline(cin, title);
                cout << "Enter job description: ";
                getline(cin, description);
                cout << "Enter company name: ";
                getline(cin, company);
                portal.addJob(title, description, company);
                break;

            case 2:
                portal.listJobs();
                break;

            case 3:
                size_t jobId;
                cout << "Enter job ID to apply for: ";
                cin >> jobId;
                portal.applyForJob(jobId);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
