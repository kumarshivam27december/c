                                
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int xorTill(int n){
    // Check if n is
    // congruent to 1 modulo 4
    if(n%4 == 1){
        return 1; 
    }
    // Check if n is congruent
    // to 2 modulo 4
    else if(n%4 == 2){
        return n+1; 
    }
    // Check if n is
    // congruent to 3 modulo 4
    else if(n%4 == 3){
        return 0; 
    }
    // Return condition
    // when n is a multiple
    else{
        return n; 
    }
}

// Function to compute XOR of
// numbers in the range [L, R]
int xorInRange(int L, int R){
    // Compute XOR of numbers from 1 to L-1
    // and 1 to R using the xorTill function
    int xorTillL = xorTill(L-1);
    int xorTillR = xorTill(R);
    // Compute XOR of the range from L to R
    return xorTillL ^ xorTillR;
}


int main() {
    int L = 3;
    int R = 19;
    int ans = xorInRange(L, R);
    cout << "XOR of of Numbers from " << L;
    cout << " to " << R << ": "<< ans << endl;
    return 0;
}