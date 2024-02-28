#include <iostream>

using namespace std;

bool canShuffle(int n, int m) {
    if((n*m)%2==0){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (canShuffle(n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
