#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class User
{
private:
    string name;

public:
    User(string name) : name(name) {}

    string getName() const
    {
        return name;
    }
};
class Transaction
{
private:
    string paidBy;
    map<string, double> splitWith;
    string description;

public:
    Transaction(string paidBy, const map<string, double> &splitWith, string desc)
        : paidBy(paidBy), splitWith(splitWith), description(desc) {}

    string getPaidBy() const
    {
        return paidBy;
    }

    const map<string, double> &getSplitWith() const
    {
        return splitWith;
    }

    string getDescription() const
    {
        return description;
    }
};

class ExpenseManager
{
private:
    vector<User> users;
    vector<Transaction> history;
    map<string, map<string, double>> balances;

public:
    void addUser(string name)
    {
        users.push_back(User(name));
    }

    void addExpense(string paidBy, vector<string> involved, double amount, string type, vector<double> percentages = {}, string desc = "")
    {
        map<string, double> splitMap;

        if (type == "equal")
        {
            double splitAmt = amount / involved.size();
            for (auto &person : involved)
            {
                if (person != paidBy)
                {
                    splitMap[person] = splitAmt;
                    balances[person][paidBy] += splitAmt;
                }
            }
        }
        else if (type == "percent")
        {
            for (int i = 0; i < involved.size(); ++i)
            {
                double splitAmt = amount * (percentages[i] / 100.0);
                if (involved[i] != paidBy)
                {
                    splitMap[involved[i]] = splitAmt;
                    balances[involved[i]][paidBy] += splitAmt;
                }
            }
        }

        Transaction txn(paidBy, splitMap, desc);
        history.push_back(txn);
    }

    void showUserDashboard(const string &userName)
    {
        cout << "\n"
             << userName << "'s DASHBOARD \n";

        double totalPaidByUser = 0.0;
        double totalBorrowedByUser = 0.0;

        for (auto &txn : history)
        {
            if (txn.getPaidBy() == userName)
            {
                for (auto &entry : txn.getSplitWith())
                {
                    cout << "You paid ₹" << fixed << setprecision(2) << entry.second
                         << " for " << entry.first
                         << " (Reason: " << txn.getDescription() << ")" << endl;
                    totalPaidByUser += entry.second;
                }
            }
            else
            {
                auto splits = txn.getSplitWith();
                if (splits.find(userName) != splits.end())
                {
                    cout << "You borrowed ₹" << fixed << setprecision(2) << splits[userName]
                         << " from " << txn.getPaidBy()
                         << " (Reason: " << txn.getDescription() << ")" << endl;
                    totalBorrowedByUser += splits[userName];
                }
            }
        }

        double net = totalPaidByUser - totalBorrowedByUser;
        cout << "\nSUMMARY\n";
        cout << "Total Paid for Others: ₹" << fixed << setprecision(2) << totalPaidByUser << endl;
        cout << "Total Borrowed from Others: ₹" << fixed << setprecision(2) << totalBorrowedByUser << endl;

        cout << endl
             << endl;
        if (net > 0)
        {
            cout << "You are owed ₹" << fixed << setprecision(2) << net << endl;
        }
        else if (net < 0)
        {
            cout << "You owe ₹" << fixed << setprecision(2) << -net << endl;
        }
        else
        {
            cout << "All settled up. No pending balances!" << endl;
        }
    }

    void showTransactions()
    {
        cout << endl
             << "transactions" << endl;
        for (auto &txn : history)
        {
            cout << txn.getPaidBy() << " paid for " << txn.getDescription() << ":\n";
            for (auto &p : txn.getSplitWith())
            {
                cout << "  - " << p.first << " owes ₹" << fixed << setprecision(2) << p.second << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    ExpenseManager app;
    app.addUser("rahul");
    app.addUser("himanshu");
    app.addUser("subash");
    app.addUser("shivam");
    app.addUser("abhay");

    app.addExpense("shivam", {"shivam", "abhay", "sourav"}, 300, "equal", {}, "Lunch");
    app.addExpense("sourav", {"shivam", "sourav", "abhay"}, 300, "equal", {}, "Lunch");
    app.addExpense("himanshu", {"rahul", "himanshu"}, 200, "percent", {70, 30}, "Movie Tickets");
    app.addExpense("abhay", {"rahul", "himanshu", "abhay"}, 1000, "percent", {50, 30, 20}, "Pizza Party");
    app.addExpense("shivam", {"rahul", "himanshu", "abhay", "shivam"}, 3000, "percent", {40, 30, 20, 10}, "Trip");

    string user;
    cout << endl
         << "Enter your user name: ";
    cin >> user;
    app.showUserDashboard(user);
    app.showTransactions();

    return 0;
}