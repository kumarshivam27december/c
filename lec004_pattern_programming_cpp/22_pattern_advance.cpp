/*
1234554321
1234**4321
123****321
12******21
1********1

*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int t1 = 1;
        while (t1 <= n - i + 1)
        {
            cout << t1;
            t1++;
        }

        int star1 = 1;
        while (star1 <= i - 1)
        {
            cout << "*";
            star1++;
        }

        int star2 = i - 1;
        while (star2 >= 1)
        {
            cout << "*";
            star2--;
        }

        int j = n - i + 1;
        while (j >= 1)
        {
            cout << j;
            j--;
        }

        cout << endl;
        i++;
    }

    return 0;
}
