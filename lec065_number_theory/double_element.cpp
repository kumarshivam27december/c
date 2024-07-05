#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int finddublicate(vector<int>&ans){
    // find all sum
    // find the sum of the array
    // find the sum of n natural number decrease in it
    int sum = 0;
    for(auto i:ans){
        sum+=i;
    }
    int sum_of_natural_number = 0;
    for(int i = 0;i<ans.size();i++){
        sum_of_natural_number+=i;
    }

    return sum-sum_of_natural_number;
}
int find_dublicate_using_xor(vector<int>&ans){
    int bns = ans[0];
    for(int i = 1;i<ans.size();i++){
        bns^=ans[i];
    }

    int bns2 = 0;
    for(int i = 0;i<ans.size();i++){
        bns2^=i;
    }
    int ans2 = (bns^bns2);
    return ans2;
}
int main()
{
    clock_t tStart = clock();
    vector<int>ans={1,2,3,4,3};
    cout<<finddublicate(ans)<<endl;
    cout<<find_dublicate_using_xor(ans)<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}