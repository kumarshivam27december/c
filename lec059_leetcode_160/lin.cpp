#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int ans(string a,string b){
   int cnt = a.size();int same = 0;
   for (int i = 0; i < a.size(); i++)
   {
    for (int j = 0; j < b.size(); j++)
    {
        if(a[i]==b[j]){
            same++;
        }
    }
    
   }
   
    return cnt+same;
}
int main()
{
    clock_t tStart = clock();
    string a = "efgh";
    string b = "jghi";
    cout<<ans(a,b);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}