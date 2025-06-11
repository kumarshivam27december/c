#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void display() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nYear: " << year << "\n\n";
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        int year;

        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter publication year: ";
        cin >> year;
        cin.ignore();

        books.push_back(Book(title, author, year));
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }
        for (const auto& book : books)
            book.display();
    }

    void searchBook() {
        string searchTitle;
        cout << "Enter title to search: ";
        getline(cin, searchTitle);
        bool found = false;

        for (const auto& book : books) {
            if (book.title == searchTitle) {
                cout << "Book found:\n";
                book.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. View Books\n3. Search Book\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from input buffer

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.viewBooks(); break;
            case 3: lib.searchBook(); break;
            case 4: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
