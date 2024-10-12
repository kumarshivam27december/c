#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
    int year;

    Book(int id, string title, string author, int year)
        : id(id), title(title), author(author), year(year) {}
};

// Library Management System class
class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        int id, year;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); // Ignore the newline after entering the ID

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Book Author: ";
        getline(cin, author);

        cout << "Enter Publication Year: ";
        cin >> year;

        Book newBook(id, title, author, year);
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }

        cout << "\nLibrary Books:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << "\nTitle: " << book.title
                 << "\nAuthor: " << book.author << "\nYear: " << book.year << "\n\n";
        }
    }

    void searchBook() {
        int searchId;
        cout << "Enter Book ID to search: ";
        cin >> searchId;

        for (const auto& book : books) {
            if (book.id == searchId) {
                cout << "\nBook found:\n";
                cout << "ID: " << book.id << "\nTitle: " << book.title
                     << "\nAuthor: " << book.author << "\nYear: " << book.year << "\n";
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void deleteBook() {
        int deleteId;
        cout << "Enter Book ID to delete: ";
        cin >> deleteId;

        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == deleteId) {
                books.erase(it);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void menu() {
        while (true) {
            int choice;
            cout << "\nLibrary Management System Menu:\n";
            cout << "1. Add Book\n";
            cout << "2. Display Books\n";
            cout << "3. Search Book\n";
            cout << "4. Delete Book\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    displayBooks();
                    break;
                case 3:
                    searchBook();
                    break;
                case 4:
                    deleteBook();
                    break;
                case 5:
                    cout << "Exiting the program." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    Library library;
    library.menu();
    return 0;
}
