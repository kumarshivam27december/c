#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    int i = 0;
    int n = s.length();
    for (int j = 1; j < n; j++) {
        if (i >= 0 && s[i] != s[j]) {
            s[++i] = s[j];
        }
    }
    return s.substr(0, i + 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Read a complete line
    
    string result = removeDuplicates(input);
    cout << "String with duplicates removed: " << result << endl;
    
    return 0;
}
