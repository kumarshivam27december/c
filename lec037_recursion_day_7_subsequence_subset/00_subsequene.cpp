#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, string str, string output, int i) {
    // Base case
    if (i >= str.length()) {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }

    // Exclude
    solve(ans, str, output, i + 1);

    // Include
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    solve(ans, str, output, 0);
    return ans;
}

int main() {
    string input_str = "abc"; // Example input

    vector<string> result = subsequences(input_str);

    // Output the subsequences
    for (const string& subseq : result) {
        cout << subseq << " ";
    }
    cout << endl;

    return 0;
}
