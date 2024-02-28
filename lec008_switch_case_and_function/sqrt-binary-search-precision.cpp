#include <iostream>
using namespace std;

int sqrtInteger(int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    int ans = -1;
    while (s <= e)
    {
        int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempans)
{
    double factor = 1;
    double ans = tempans;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j <= n; j += factor)
        {
            if ((j + factor) * (j + factor) > n)
            {
                ans = j;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int tempans = sqrtInteger(n);
    cout << morePrecision(n, 4, tempans) << endl;

    return 0;
}

