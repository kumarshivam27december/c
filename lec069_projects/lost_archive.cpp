#include <iostream>
#include <map>
#include <vector>

using namespace std;

// --- Red-Black Tree (Ordered Book Search) ---
class RedBlackTree {
private:
    map<string, string> books; // Simulating RB tree with an ordered map
public:
    void addBook(string title, string content) { books[title] = content; }
    string searchBook(string title) {
        return books.count(title) ? books[title] : "Book not found.";
    }
    void displayBooks() {
        cout << "Books in this section:\n";
        for (auto& book : books) cout << "  - " << book.first << endl;
    }
};

// --- M-ary Tree (Library Structure) ---
class LibrarySection {
public:
    string name;
    RedBlackTree bookCollection;
    vector<LibrarySection*> subsections;

    LibrarySection(string n) : name(n) {}
    void addSubsection(LibrarySection* section) { subsections.push_back(section); }
};

// --- Game Class ---
class AdventureGame {
private:
    LibrarySection* root;
    LibrarySection* currentSection;

public:
    AdventureGame() {
        root = new LibrarySection("Entrance Hall");
        LibrarySection* history = new LibrarySection("History Wing");
        LibrarySection* magic = new LibrarySection("Magic Section");
        LibrarySection* science = new LibrarySection("Science Section");

        history->bookCollection.addBook("The Lost Kingdoms", "A history of forgotten civilizations.");
        history->bookCollection.addBook("Ancient Wars", "Tales of battles long past.");

        magic->bookCollection.addBook("Spell of Fire", "How to conjure flames.");
        magic->bookCollection.addBook("The Ancient Tome", "A legendary book of forgotten spells."); // Goal book!

        science->bookCollection.addBook("The Cosmos", "A deep dive into the universe.");
        science->bookCollection.addBook("Alchemy", "The science of transmutation.");

        root->addSubsection(history);
        root->addSubsection(magic);
        root->addSubsection(science);

        currentSection = root;
    }

    void explore() {
        while (true) {
            cout << "\n📖 You are in: " << currentSection->name << endl;
            currentSection->bookCollection.displayBooks();
            
            if (!currentSection->subsections.empty()) {
                cout << "Sections to explore:\n";
                for (size_t i = 0; i < currentSection->subsections.size(); i++)
                    cout << "  " << i + 1 << ". " << currentSection->subsections[i]->name << endl;
                cout << "Enter the number to explore or '0' to stay: ";
                
                int choice;
                cin >> choice;
                if (choice > 0 && choice <= (int)currentSection->subsections.size())
                    currentSection = currentSection->subsections[choice - 1];
            }

            cout << "\nEnter a book name to search or 'exit' to leave: ";
            string bookName;
            cin.ignore();
            getline(cin, bookName);
            
            if (bookName == "exit") break;
            cout << "📚 " << currentSection->bookCollection.searchBook(bookName) << endl;

            if (bookName == "The Ancient Tome") {
                cout << "\n🎉 You found the legendary Ancient Tome! You win! 🎉\n";
                break;
            }
        }
    }
};

// --- Main ---
int main() {
    AdventureGame game;
    game.explore();
    return 0;
}
