#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, b.title);
    cout << "Enter author name: ";
    getline(cin, b.author);
    cout << "Enter publication year: ";
    cin >> b.year;
    library.push_back(b);
    cout << "Book added successfully!\n";
}

void viewBooks() {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "\nList of books:\n";
    for (size_t i = 0; i < library.size(); ++i) {
        cout << i + 1 << ". " << library[i].title
             << " by " << library[i].author
             << " (" << library[i].year << ")\n";
    }
}

void searchBook() {
    cout << "Enter title to search: ";
    cin.ignore();
    string title;
    getline(cin, title);

    bool found = false;
    for (const auto& b : library) {
        if (b.title == title) {
            cout << "Found: " << b.title << " by " << b.author << " (" << b.year << ")\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Book not found.\n";
}

void deleteBook() {
    cout << "Enter title to delete: ";
    cin.ignore();
    string title;
    getline(cin, title);

    auto it = remove_if(library.begin(), library.end(), [&](Book& b) {
        return b.title == title;
    });

    if (it != library.end()) {
        library.erase(it, library.end());
        cout << "Book deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Library Management Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Delete Book by Title\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
