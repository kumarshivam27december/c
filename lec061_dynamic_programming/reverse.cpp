#include <bits/stdc++.h>
#include <time.h>
using namespace std;
string helper(string &str,int s,int e){
    if(s>=e) return str;

    swap(str[s],str[e]);
    return helper(str,s+=1,e-=1);
}
string reversing(string &str){
    int start = 0;
    int ending = str.length()-1;
    return helper(str,start,ending);
}
int main()
{
    clock_t tStart = clock();
    string str1 = "moyemoye";
    cout<<reversing(str1);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}