#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// Singleton Printer Spooler
class PrinterSpooler {
private:
    static PrinterSpooler* instance;  // Single instance pointer
    static mutex mtx;                 // Mutex for thread safety

    // Private constructor to prevent object creation from outside
    PrinterSpooler() {
        cout << "PrinterSpooler Initialized." << endl;
    }

    // Delete copy constructor and assignment
    PrinterSpooler(const PrinterSpooler&) = delete;
    PrinterSpooler& operator=(const PrinterSpooler&) = delete;

public:
    // Static method to get the instance (Lazy initialization)
    static PrinterSpooler* getInstance() {
        lock_guard<mutex> lock(mtx); // Thread safety
        if (instance == nullptr) {
            instance = new PrinterSpooler();
        }
        return instance;
    }

    void printDocument(const string& documentName) {
        cout << "Printing Document: " << documentName << " from " << this << endl;
    }
};

// Static member definitions
PrinterSpooler* PrinterSpooler::instance = nullptr;
mutex PrinterSpooler::mtx;

// Driver Code
void userPrintJob(const string& name) {
    PrinterSpooler* spooler = PrinterSpooler::getInstance();
    spooler->printDocument(name);
}

int main() {
    thread t1(userPrintJob, "Report_A.pdf");
    thread t2(userPrintJob, "Resume.docx");
    thread t3(userPrintJob, "Invoice.xlsx");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
