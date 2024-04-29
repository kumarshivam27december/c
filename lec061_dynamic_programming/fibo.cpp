#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int fibo(int num){
    if(num<1) return 1;


    return num*fibo(num-1);

}
int main()
{
    clock_t tStart = clock();
    cout<<fibo(5);
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}