#include <bits/stdc++.h>
using namespace std;
int binaryXor(string s1,string s2){
    int a = stoi(s1);
    int b = stoi(s2);
    int ans = 0;
    int i = 0;
    while(a>0 || b>0){
        int digit1 = a%10;
        int digit2 = b%10;
        int c = digit1^digit2;
        if(c==1){    
            ans = ans + pow(2,i);
            i++;
        }
        
        a/=10;
        b/=10;
    }
    return ans;
}
int main(){
    string s1 = "101";
    string s2 = "010";
    cout<<binaryXor(s1,s2)<<endl;
    return 0;
}

