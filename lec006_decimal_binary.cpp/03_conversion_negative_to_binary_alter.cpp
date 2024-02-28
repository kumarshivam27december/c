#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string binary = "";
    
    if (n == 0) {
        binary = "0";
    } else {
        int numBits = sizeof(n) * 8;
        for (int i = numBits - 1; i >= 0; i--) {
            int bit = (n >> i) & 1;
            binary += to_string(bit);
        }
    }
    
    cout << "Binary representation: " << binary << endl;
    
    return 0;
}
