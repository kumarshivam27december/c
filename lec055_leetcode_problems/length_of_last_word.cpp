#include <bits/stdc++.h>
using namespace std;
int lengthOfLastWord(string s) {
        int index = -1;
        int len = s.size();
        if(len==0) return 0;
        if (len == 1) return isalnum(s[0]) ? 1 : 0;

        for(int i = len-1;i>=0;i--){
            if(isalnum(s[i])){
                index = i;
                break;
            }
        }
        int j = 1; //because of case " a "

        for(int i = 0;i<index;i++){
            if(s[i]==' '){
                j = 0;
            }
            j++;
            
        }
        return j;
}
int main(){
    string str = "Hello world ";
    cout<<lengthOfLastWord(str)<<endl;
    return 0;
}
