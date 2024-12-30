/*
GCD Queries
You are given an array \( A \) consisting of \( N \) integers along with \( Q \) queries.
For each query:
- Given an integer \( X \), print and remove the minimum element in the array \( k \), such that \( \text{gcd}(X, k) > 1 \), where gcd denotes the greatest common divisor.
- If no value in the array satisfies the condition, print and remove the minimum element of the array.
### Input Format
- The first line of input contains a single integer \( T \), denoting the number of test cases.
- Each test case consists of multiple lines of input:
  1. The first line of each test case contains a single integer \( N \)—the number of elements in the array.
  2. The second line contains \( N \) space-separated integers \( A_1, A_2, \dots, A_N \)—the elements of the array \( A \).
  3. The third line contains a single integer \( Q \), denoting the number of queries.
  4. The fourth line contains \( Q \) space-separated integers \( X_1, X_2, \dots, X_Q \)—the queries.
### Output Format
For each test case, print \( Q \) space-separated integers denoting the answer to each query.
### Constraints
- \( 1 <= T <= 10^5 \)
- \( 1 <= Q, N <= 2 \cdot 10^5 \)
- \( 1 <= A_i, X_i <= 10^6 \)
- The sum of \( N \) over all test cases will not exceed \( 2 \cdot 10^5 \).
- The sum of \( Q \) over all test cases will not exceed \( 2 \cdot 10^5 \).
### Sample Input
1
5
2 9 3 15 10
4
2 2 3 7
### Sample Output
2 10 3 9
### Explanation
Test case 1: The given array is \( [2, 9, 3, 15, 10] \), and there are 4 queries:
1. Query 1: Given \( X = 2 \). The elements \( 2 \) and \( 10 \) satisfy the condition. Since \( 2 \) is smaller, we print and remove \( 2 \) from the array. The array becomes \( A = [9, 3, 15, 10] \).
2. Query 2: Given \( X = 2 \). The element \( 10 \) satisfies the condition. We print and remove \( 10 \) from the array. The array becomes \( A = [9, 3, 15] \).
3. Query 3: Given \( X = 3 \). The elements \( 3 \) and \( 9 \) satisfy the condition. Since \( 3 \) is smaller, we print and remove \( 3 \) from the array. The array becomes \( A = [9, 15] \).
4. Query 4: Given \( X = 7 \). No element satisfies the condition, so we select \( 9 \) (the smallest element present). We print and remove \( 9 \) from the array. The array becomes \( A = [15] \).
Now you can copy-paste the question!
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n + 10];
        int forward[n + 10];
        int backward[n + 10];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        forward[0] = backward[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            forward[i] = __gcd(forward[i - 1], arr[i]);
        }

        for (int i = n; i >= 1; i--)
        {
            backward[i] = __gcd(backward[i + 1], arr[i]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(forward[l - 1], backward[r + 1]) << endl;
        }
    }

    return 0;
}