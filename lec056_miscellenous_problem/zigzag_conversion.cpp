#include <bits/stdc++.h>
using namespace std;
string zigzag_conversion(string str,int numrow){
    if(numrow==1){
        return str;
    }
    vector<string> ans(numrow);
    bool flag = false;
    int i =0;
    for(auto ch:str){
        ans[i]+=ch;
        if(i==0 || i==numrow-1){
            flag = !flag;
        }
        if(flag){
            i+=1;
        }else{
            i-=1;
        }
    }

    string zigzag = "";
    for(auto str:ans){
        zigzag+=str;
    }
    return zigzag;
}
int main(){
    string str = "PAYPALISHIRING";
    int numrow = 3;
    cout<<zigzag_conversion(str,numrow)<<endl;
    return 0;
}