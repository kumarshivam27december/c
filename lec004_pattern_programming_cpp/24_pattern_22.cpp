#include <iostream>
using namespace std;
/*
5


54321
 4321
  321
   21
    1



*/
int main()
{
    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int space = 1;
        while (space <= i - 1)
        {
            cout << " ";
            space++;
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
