#include <bits/stdc++.h>
#include <time.h>
using namespace std;
bool helper(string a,int s,int e){

    if(s>=e) return true;

    if(a[s]!=a[e]) return false;

    return helper(a,s+1,e-1);
}
bool pali(string a){
    int s = 0;
    int e = a.length()-1;
    return helper(a,s,e);
}

int main()
{
    clock_t tStart = clock();
    string a = "mam";
    cout<<pali(a);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}