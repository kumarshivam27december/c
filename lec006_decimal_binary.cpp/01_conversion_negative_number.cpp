#include <iostream>
#include <cmath>
using namespace std;

string toBinary(int n) {
    if (n == 0) {
        return "0";
    }
    
    string binary = "";
    
    while (n != 0) {
        int bit = abs(n % 2);
        binary = to_string(bit) + binary;
        n /= 2;
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
