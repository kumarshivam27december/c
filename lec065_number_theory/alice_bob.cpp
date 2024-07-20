#include <bits/stdc++.h>
using namespace std;

string losingPlayer(int x, int y) {
    int totalValue = 115; // Total value of coins in each turn
    vector<bool> dp(totalValue + 1, false);
    dp[0] = false;
    dp[1] = true;

    for (int i = 2; i <= totalValue; i++) {
        if (i - 1 >= 0 && !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 && !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 && !dp[i - y])
            dp[i] = true;
        else
            dp[i] = false;
    }

    if (dp[totalValue])
        return "Alice";
    else
        return "Bob";
}

int main() {
    int x = 1, y = 1; // Example values
    cout << losingPlayer(x, y) << endl;
    return 0;
}
