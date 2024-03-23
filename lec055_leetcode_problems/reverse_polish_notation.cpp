#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> res;
        for (int i = 0; i < tokens.size(); i++) {
            int x = res.size();
            int a = 0;
            if (tokens[i] == "+") {
                a = res[x - 2] + res[x - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(a);
            } else if (tokens[i] == "-") {
                a = res[x - 2] - res[x - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(a);
            } else if (tokens[i] == "*") {
                a = res[x - 2] * res[x - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(a);
            } else if (tokens[i] == "/") {
                a = res[x - 2] / res[x - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(a);
            } else {
                stringstream ss;
                ss << tokens[i];
                ss >> a;
                res.push_back(a);
            }
        }
        return res[0];
    }
};

int main() {
    vector<string> tokens;
    string token;

    cout << "Enter the RPN expression (separated by spaces): ";
    // Get input for the RPN expression token by token
    while (getline(cin, token)) {
        if (token == "") {
            break;
        }
        tokens.push_back(token);
    }

    Solution sol;
    int result = sol.evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
