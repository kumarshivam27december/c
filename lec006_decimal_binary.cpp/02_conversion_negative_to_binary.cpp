#include <iostream>
using namespace std;

string toBinary(int n) {
    if (n == 0) {
        return "0";
    }
    
    string binary = "";
    
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        binary += to_string(bit);
    }
    
    return binary;
}

int main() {
    int n;
    cin >> n;
    
    string binary = toBinary(n);
    
    cout << "Binary representation: " << binary << endl;
    
    return 0;
}
