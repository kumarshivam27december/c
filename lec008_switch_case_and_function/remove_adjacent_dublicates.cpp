#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "abbaca";
    int i = 0;
    
    while (i < str.length() - 1) {
        int j = i + 1;
        
        if (str[i] != str[j]) {
            i++;
            j++;
        } else {
            str.erase(i, 1);
            str.erase(j, 1);
            i--;
            j++;
        }
    }
    
    cout << str << endl;
    
    return 0;
}

