#include <bits/stdc++.h>
#include <time.h>
using namespace std;
string sumstring(string a,string b){
    int k = a.size();
    int l = b.size();
    string m;string n;string ans="";
    if(k>l) {
        m=b;
        n=a;
    }else{
        m=a;
        n=b;
    }
    reverse(m.begin(),m.end());
    int length_diff = abs(k-l);
    while(length_diff--){
        m.push_back('0');
    }
    reverse(m.begin(),m.end());

    int carry =0;
    for(int i = m.length()-1;i>=0;i--){
        int augment = m[i]-'0';
        int addend = n[i]-'0';
        int sum = augment+addend+carry;
        if(sum>10){
            carry = 1;
            sum-=10;
        }
        ans.push_back(sum+'0');

    }

   reverse(ans.begin(),ans.end());
   return ans;

}
int main()
{
    clock_t tStart = clock();
    string a = "456";
    string b = "77";
    cout<<sumstring(a,b)<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}