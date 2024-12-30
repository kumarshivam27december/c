/*
given 2d array a of 
n*n integers. given q queries in each query given a,b,c and d print sum of square represented by (a,b) as left point and (c,d) as bottom right point
constraints
1 to n to 10^3
1 to a[i][j] to 10^9
1 to q to 10^5
1 to a,b,c,d to n
*/



#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int arr[N][N];
long long pf[N][N];
int main() {
    int n;
    cin>>n;
    pf[0][0]=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>arr[i][j];
            pf[i][j]=arr[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1]<<endl;
    }
    return 0;
}



