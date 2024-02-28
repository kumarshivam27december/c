#include <bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        ans = ans | (n & 1);
        n >>= 1;
    }

    return ans;
}
int main()
{
    uint32_t a = 1011;
    cout << reverseBits(a) << endl;
    return 0;
}