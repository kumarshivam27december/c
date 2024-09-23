#include <iostream>
#include <string>
#include <map>

using namespace std;

class VotingSystem {
private:
    map<string, int> candidates;
    int totalVotes;

public:
    VotingSystem() {
        totalVotes = 0;
    }

    // Function to add a candidate
    void addCandidate(const string& name) {
        candidates[name] = 0;
    }

    // Function to cast a vote for a candidate
    void vote(const string& name) {
        if (candidates.find(name) != candidates.end()) {
            candidates[name]++;
            totalVotes++;
            cout << "Vote successfully cast for " << name << "!\n";
        } else {
            cout << "Candidate not found!\n";
        }
    }

    // Function to display voting results
    void displayResults() const {
        cout << "\nVoting Results:\n";
        for (const auto& candidate : candidates) {
            cout << candidate.first << " - " << candidate.second << " votes ("
                 << (totalVotes > 0 ? (candidate.second * 100.0 / totalVotes) : 0.0) << "%)\n";
        }
        cout << "Total votes: " << totalVotes << "\n";
    }
};

int main() {
    VotingSystem votingSystem;
    int choice;
    string name;

    // Adding candidates
    cout << "Enter the number of candidates: ";
    int numCandidates;
    cin >> numCandidates;
    cin.ignore(); // To ignore the newline character after entering the number

    for (int i = 0; i < numCandidates; i++) {
        cout << "Enter candidate name " << (i + 1) << ": ";
        getline(cin, name);
        votingSystem.addCandidate(name);
    }

    // Voting process
    do {
        cout << "\n1. Cast Vote\n2. Show Results\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter candidate name to vote for: ";
            getline(cin, name);
            votingSystem.vote(name);
            break;
        case 2:
            votingSystem.displayResults();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
