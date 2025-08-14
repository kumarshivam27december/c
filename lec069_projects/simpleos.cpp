// mini_os.cpp
// A single-file "MiniOS" terminal app — simple shell-like experience.
// Compile: g++ mini_os.cpp -o mini_os -std=c++17
// Run: ./mini_os

#include <bits/stdc++.h>
#include <filesystem>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
namespace fs = std::filesystem;

// ---------- Utilities ----------
void slowPrint(const string &s, int ms = 25) {
    for (char c : s) { cout << c; cout.flush(); this_thread::sleep_for(chrono::milliseconds(ms)); }
    cout << endl;
}

void cls() {
    // ANSI clear screen — works on most terminals
    cout << "\x1B[2J\x1B[H";
}

string nowString() {
    auto t = chrono::system_clock::to_time_t(chrono::system_clock::now());
    string s = std::ctime(&t);
    if(!s.empty() && s.back() == '\n') s.pop_back();
    return s;
}

double toDoubleSafe(const string &s, bool &ok) {
    try { size_t idx; double v = stod(s, &idx); ok = (idx == s.size()); return v; }
    catch(...) { ok = false; return 0.0; }
}

// ---------- Very small expression evaluator (shunting-yard -> RPN) ----------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
bool isOp(char c){ return c=='+'||c=='-'||c=='*'||c=='/'; }

vector<string> tokenizeExpr(const string &expr) {
    vector<string> tokens;
    string num;
    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        if (isspace((unsigned char)c)) continue;
        if (isdigit((unsigned char)c) || c=='.') {
            num.push_back(c);
        } else {
            if (!num.empty()) { tokens.push_back(num); num.clear(); }
            if (isOp(c) || c=='(' || c==')') {
                string t(1, c);
                tokens.push_back(t);
            } else {
                // invalid char -> treat as token (will error later)
                string t(1, c);
                tokens.push_back(t);
            }
        }
    }
    if (!num.empty()) tokens.push_back(num);
    return tokens;
}

bool infixToRPN(const vector<string> &tokens, vector<string> &out, string &err) {
    vector<string> stackOp;
    for (auto &t : tokens) {
        if (t.empty()) continue;
        if ( (isdigit((unsigned char)t[0]) || (t.size()>1 && t[0]=='.')) ) {
            out.push_back(t);
        } else if (t == "+" || t == "-" || t == "*" || t == "/") {
            char op = t[0];
            while (!stackOp.empty()) {
                string top = stackOp.back();
                if (top == "(") break;
                char topc = top[0];
                if ( precedence(topc) >= precedence(op) ) {
                    out.push_back(top);
                    stackOp.pop_back();
                } else break;
            }
            stackOp.push_back(t);
        } else if (t == "(") {
            stackOp.push_back(t);
        } else if (t == ")") {
            bool found = false;
            while (!stackOp.empty()) {
                string top = stackOp.back(); stackOp.pop_back();
                if (top == "(") { found = true; break; }
                out.push_back(top);
            }
            if (!found) { err = "Mismatched parentheses"; return false; }
        } else {
            err = "Invalid token '" + t + "'";
            return false;
        }
    }
    while (!stackOp.empty()) {
        if (stackOp.back() == "(" || stackOp.back() == ")") { err = "Mismatched parentheses"; return false; }
        out.push_back(stackOp.back()); stackOp.pop_back();
    }
    return true;
}

bool evalRPN(const vector<string> &rpn, double &result, string &err) {
    vector<double> st;
    for (auto &t : rpn) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            if (st.size() < 2) { err = "Malformed expression"; return false; }
            double b = st.back(); st.pop_back();
            double a = st.back(); st.pop_back();
            if (t == "+") st.push_back(a + b);
            if (t == "-") st.push_back(a - b);
            if (t == "*") st.push_back(a * b);
            if (t == "/") {
                if (b == 0) { err = "Division by zero"; return false; }
                st.push_back(a / b);
            }
        } else {
            bool ok; double v = toDoubleSafe(t, ok);
            if (!ok) { err = "Invalid number '" + t + "'"; return false; }
            st.push_back(v);
        }
    }
    if (st.size() != 1) { err = "Malformed expression"; return false; }
    result = st.back();
    return true;
}

bool evaluateExpression(const string &expr, double &res, string &err) {
    auto tokens = tokenizeExpr(expr);
    vector<string> rpn;
    if (!infixToRPN(tokens, rpn, err)) return false;
    if (!evalRPN(rpn, res, err)) return false;
    return true;
}

// ---------- MiniOS shell functions ----------
vector<string> historyCmds;
chrono::system_clock::time_point startTime;

void cmd_help() {
    cout << R"(
Available commands:
  help          - show this help
  about         - show mini-os about
  uptime        - show how long MiniOS is running
  time          - show current date & time
  clear         - clear screen
  ls            - list files & folders in current directory
  pwd           - show current working directory
  cd <dir>      - change directory
  touch <file>  - create empty file
  cat <file>    - show file contents
  edit <file>   - simple line editor (end with .save on its own line)
  rm <file>     - remove file
  mkdir <dir>   - create directory
  rmdir <dir>   - remove (empty) directory
  calc <expr>   - evaluate expression. ex: calc (1+2)*3/4 - supports + - * / and ()
  ps            - show simple fake process list
  history       - show command history
  echo <text>   - prints text
  exit | quit   - exit MiniOS
)";
}

void cmd_about() {
    cout << "MiniOS - tiny single-file demo OS shell. Written in C++. (single-file)\n";
    cout << "Built-in utilities: files, edit, simple calc, fake ps, history.\n";
}

void cmd_uptime() {
    auto now = chrono::system_clock::now();
    auto diff = chrono::duration_cast<chrono::seconds>(now - startTime).count();
    long d = diff / (24*3600);
    diff %= 24*3600;
    long h = diff / 3600;
    diff %= 3600;
    long m = diff / 60;
    long s = diff % 60;
    cout << "Uptime: " << d << "d " << h << "h " << m << "m " << s << "s\n";
}

void cmd_ls(const vector<string> &args) {
    try {
        fs::path p = fs::current_path();
        if (args.size() >= 2) p = args[1];
        for (auto &entry : fs::directory_iterator(p)) {
            auto f = entry.path().filename().string();
            string type = entry.is_directory() ? "<DIR>" : "     ";
            auto sz = entry.is_regular_file() ? to_string((long long)fs::file_size(entry.path())) : "-";
            cout << type << " " << setw(20) << left << f << "  " << setw(8) << right << sz << "\n";
        }
    } catch (const std::exception &e) {
        cout << "ls error: " << e.what() << "\n";
    }
}

void cmd_pwd() {
    cout << fs::current_path().string() << "\n";
}

void cmd_cd(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: cd <dir>\n"; return; }
    try {
        fs::path p = args[1];
        fs::current_path(p);
    } catch (const std::exception &e) {
        cout << "cd error: " << e.what() << "\n";
    }
}

void cmd_touch(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: touch <file>\n"; return; }
    fs::path f = args[1];
    try {
        ofstream ofs(f, ios::app);
        ofs.close();
        cout << "Created: " << f.string() << "\n";
    } catch (const std::exception &e) {
        cout << "touch error: " << e.what() << "\n";
    }
}

void cmd_cat(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: cat <file>\n"; return; }
    fs::path f = args[1];
    try {
        if (!fs::exists(f)) { cout << "File not found\n"; return; }
        if (fs::is_directory(f)) { cout << "cat: is a directory\n"; return; }
        ifstream ifs(f);
        string line;
        while (getline(ifs, line)) cout << line << "\n";
    } catch (const std::exception &e) {
        cout << "cat error: " << e.what() << "\n";
    }
}

void cmd_rm(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: rm <file>\n"; return; }
    fs::path f = args[1];
    try {
        if (!fs::exists(f)) { cout << "Not found\n"; return; }
        if (fs::is_directory(f)) { cout << "Use rmdir to remove directories\n"; return; }
        fs::remove(f);
        cout << "Removed: " << f.string() << "\n";
    } catch (const std::exception &e) {
        cout << "rm error: " << e.what() << "\n";
    }
}

void cmd_mkdir(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: mkdir <dir>\n"; return; }
    fs::path d = args[1];
    try {
        if (fs::create_directories(d)) cout << "Created dir: " << d.string() << "\n";
        else cout << "Directory exists or failed\n";
    } catch (const std::exception &e) {
        cout << "mkdir error: " << e.what() << "\n";
    }
}

void cmd_rmdir(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: rmdir <dir>\n"; return; }
    fs::path d = args[1];
    try {
        if (!fs::exists(d)) { cout << "Not found\n"; return; }
        if (!fs::is_directory(d)) { cout << "Not a directory\n"; return; }
        fs::remove(d); // only removes empty
        cout << "Removed directory: " << d.string() << "\n";
    } catch (const std::exception &e) {
        cout << "rmdir error: " << e.what() << "\n";
    }
}

void cmd_edit(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: edit <file>\n"; return; }
    fs::path f = args[1];
    cout << "Simple editor for '" << f.string() << "'. Type lines. On a single line enter .save to save and exit, .quit to exit w/o saving.\n";
    vector<string> buffer;
    if (fs::exists(f) && fs::is_regular_file(f)) {
        ifstream ifs(f);
        string line;
        while (getline(ifs, line)) buffer.push_back(line);
    }
    cout << "Entering editor (current " << buffer.size() << " lines). New input below:\n";
    string line;
    // show current and then append; user edits by writing fresh content
    while (true) {
        cout << "> ";
        if (!std::getline(cin, line)) break;
        if (line == ".save") {
            ofstream ofs(f);
            for (auto &L : buffer) ofs << L << "\n";
            cout << "Saved " << f.string() << "\n"; break;
        } else if (line == ".quit") {
            cout << "Quit without saving\n"; break;
        } else {
            buffer.push_back(line);
        }
    }
}

void cmd_ps() {
    // Fake process list — just to give OS feel
    cout << " PID   NAME         STATE    CPU\n";
    cout << " 1001  init         SLEEP    0.1%\n";
    cout << " 1002  shell        RUNNING  1.2%\n";
    cout << " 1003  logger       SLEEP    0.0%\n";
    cout << " 1010  musicd       SLEEP    0.3%\n";
}

void cmd_history() {
    for (size_t i = 0; i < historyCmds.size(); ++i) {
        cout << setw(3) << (i+1) << "  " << historyCmds[i] << "\n";
    }
}

void cmd_calc(const vector<string> &args) {
    if (args.size() < 2) { cout << "usage: calc <expression>\n"; return; }
    string expr;
    for (size_t i = 1; i < args.size(); ++i) { if (i>1) expr += " "; expr += args[i]; }
    double res;
    string err;
    if (evaluateExpression(expr, res, err)) {
        // Print without scientific default; show many decimals if fractional
        cout.setf(std::ios::fixed); cout<<setprecision(6);
        cout << "=> " << res << "\n";
        cout.unsetf(std::ios::fixed);
    } else {
        cout << "calc error: " << err << "\n";
    }
}

// ---------- Command dispatcher ----------
void handleCommand(const string &cmdline) {
    if (cmdline.empty()) return;
    // simple split by spaces (quotes not handled)
    stringstream ss(cmdline);
    vector<string> parts;
    string tok;
    while (ss >> tok) parts.push_back(tok);
    if (parts.empty()) return;
    string cmd = parts[0];
    historyCmds.push_back(cmdline);

    if (cmd == "help") cmd_help();
    else if (cmd == "about") cmd_about();
    else if (cmd == "uptime") cmd_uptime();
    else if (cmd == "time") cout << nowString() << "\n";
    else if (cmd == "clear") cls();
    else if (cmd == "ls") cmd_ls(parts);
    else if (cmd == "pwd") cmd_pwd();
    else if (cmd == "cd") cmd_cd(parts);
    else if (cmd == "touch") cmd_touch(parts);
    else if (cmd == "cat") cmd_cat(parts);
    else if (cmd == "rm") cmd_rm(parts);
    else if (cmd == "mkdir") cmd_mkdir(parts);
    else if (cmd == "rmdir") cmd_rmdir(parts);
    else if (cmd == "edit") cmd_edit(parts);
    else if (cmd == "ps") cmd_ps();
    else if (cmd == "history") cmd_history();
    else if (cmd == "calc") cmd_calc(parts);
    else if (cmd == "echo") {
        for (size_t i = 1; i < parts.size(); ++i) { if(i>1) cout << " "; cout << parts[i]; }
        cout << "\n";
    }
    else if (cmd == "exit" || cmd == "quit") {
        cout << "Shutting down MiniOS...\n"; exit(0);
    }
    else {
        cout << "Unknown command: " << cmd << ". Try 'help'.\n";
    }
}

// ---------- Boot animation ----------
void bootSequence() {
    cls();
    slowPrint("MiniOS Bootloader v0.1", 35);
    slowPrint("Checking hardware...", 18);
    this_thread::sleep_for(chrono::milliseconds(200));
    slowPrint(" - CPU: virtual 2 cores", 10);
    slowPrint(" - RAM: 256MB (simulated)", 10);
    slowPrint(" - Storage: virtual disk", 10);
    for (int i=0;i<=100;i+=20) {
        cout << "Booting: " << i << "%\r"; cout.flush(); this_thread::sleep_for(chrono::milliseconds(150));
    }
    cout << "Booting: 100%\n";
    slowPrint("Welcome to MiniOS!", 35);
    cout << "Type 'help' to see commands.\n\n";
}

// ---------- Main ----------
int main() {
    startTime = chrono::system_clock::now();
    bootSequence();
    string line;
    while (true) {
        try {
            cout << "[" << fs::current_path().filename().string() << "] minios> ";
            if (!std::getline(cin, line)) { cout << "\n"; break; }
            // simple trim front/back
            size_t a = line.find_first_not_of(" \t\r\n");
            if (a == string::npos) continue;
            size_t b = line.find_last_not_of(" \t\r\n");
            string trimmed = line.substr(a, b - a + 1);
            handleCommand(trimmed);
        } catch (const std::exception &e) {
            cout << "Shell error: " << e.what() << "\n";
        }
    }
    cout << "Bye!\n";
    return 0;
}
