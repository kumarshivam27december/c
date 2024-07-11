#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void solve(int n){
    if(n<=0) return;
    cout<<n<<" ";
    solve(n-1);
}
int main()
{
    clock_t tStart = clock();
    solve(5);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}