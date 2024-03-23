/*
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant
 in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1]+=1;
        int carry = 0;
        for(int i = n-1;i>=0;i--){
            digits[i]+=carry;
            carry = digits[i]/10;
            digits[i] = digits[i]%10;
        }

        if(carry){
            digits.insert(digits.begin(),carry);
        }

        return digits;
    }
};
int main() {
    Solution sol;
    vector<int> digits = {9, 9, 9};
    vector<int> result = sol.plusOne(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}