#include <bits/stdc++.h>
#include <time.h>
using namespace std;
// to check if the last bit is zero or one using odd or even
// to remove last bit divide by 2
/*if a is very large
take the modules at first only of a */
/*
if m is very large 1e18
if we multiply will not be modulated hence
cannot be stored
so instead we can add it a b times
this is solved using binary multiplication
if b is very big
then it can be solved using etf Euler Totient Function
if m is prime
etf or phi(m) = m-1;
a^((b^c)%M-1)%M
phi(m) = m * summation of(1-(1/m));
 */
/*binary multiplication
     which is expo function below
*/
long long expo(long long a, long long b, long long int M)
{
    if (b == 0)
        return 0;
    long long k = expo(a, b / 2, M);
    k = (k + k) % M;
    if (b % 2 == 0)
        return k;
    else
        return (k + a) % M;
}
// recursive approach
long long binary_exp(long long a, long long b, long long int M)
{
    if (b == 0)
        return 1;
    long long res = binary_exp(a, b / 2, M);
    if (b % 2)
    {
        // return (res*res*a)%M;
        return expo(expo(res, res, M), a, M);
    }
    else
    {
        // return (res*res)%M;
        return expo(res, res, M);
    }
}
// iterative approach
long long bin_exp(long long a, long long b, long long int M)
{
    long long result = 1;
    while (b)
    {
        // if(b&1) result = (result*a)%M;
        // if(b%2) result = (result*a)%M;
        if (b % 2)
            result = expo(result, a, M);
        // a = (a*a)%M;
        a = (expo(a, a, M));
        // b>>=1;
        b /= 2;
    }
    return result;
}
long long etf(long long a, long long b, long long c, long long int M)
{
    // a^((b^c)%M-1)%M
    long long result = bin_exp(b, c, M - 1);
    long long ans = bin_exp(a, result, M);
    return ans;
}
int main()
{
    clock_t tStart = clock();
    // calculate a^b %M
    long long int M = 1e9 + 7;
    long long a, b;
    cin >> a >> b;
    a %= M;
    cout << binary_exp(a, b, M) << endl;
    cout << bin_exp(a, b, M) << endl;
    cout << expo(a, b, M) << endl;
    cout << etf(20, 2, 21, M) << endl;
    cout << endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart) / (CLOCKS_PER_SEC / 1000000));
    cout << endl;
    return 0;
}