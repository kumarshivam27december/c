#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main()
{
clock_t tStart = clock();
    int cnt = 0;
    for (int i = 0; i < 1000000000; i++)
    {
        /* code */
        cnt++;
    }
    cout<<cnt<<endl;
    
    cout<<endl;
    printf("Time taken: %.2fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}