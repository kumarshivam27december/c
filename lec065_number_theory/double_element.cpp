#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int main()
{
    clock_t tStart = clock();
    vector<int>ans={1,2,3,4,3};
    int bns = ans[0];
    for(int i = 1;i<ans.size();i++){
        bns^=ans[i];
    }

    int bns2 = 0;
    for(int i = 0;i<ans.size();i++){
        bns2^=i;
    }


    // find the sum of the array
    // find the sum of n natural number decrease in it

    int ans2 = (bns^bns2);
    cout<<ans2<<endl;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}