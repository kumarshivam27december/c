#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int candy(vector<int> &v)
{
    int size = v.size();
    if(size<=1) return size;
    vector<int> ans(size,1);
    // checking from the left to right
    for (int i = 1; i < size; i++)
    {
        if (v[i] > v[i - 1])
        {
            ans[i] = ans[i - 1] + 1;
        }
    }
    // reverse checking and checking the max of both to place
    for (int i = size - 2; i >= 0; i--)
    {
        if (v[i] > v[i + 1])
        {
            ans[i] = max(ans[i], ans[i + 1] + 1);
        }
    }
    int sum = 0;
    for (auto i : ans)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {1, 3, 2, 2, 1};
    cout << candy(v);
    cout << endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000000));
    cout << endl;
    return 0;
}