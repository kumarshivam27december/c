#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int squaring(int n) {
	if (n < 2) {
		return n;
	}
	int low = 1, high = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (mid * mid == n) {
			return mid;
		} else if (mid * mid < n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return high;
}
bool check1(int n){
    return sqrt(n)*sqrt(n)==n;
}
bool check2(int n){
    for(int i = 1;i<=n;i++){
        if(i*i==n){
            return true;
        }
    }
    return false;
}

bool check3(int n){
    for(int i = 1;i*i<=n;i++){
        if(i*i==n){
            return true;
        }
    }
    return false;
    
}bool check4(int n){
    return squaring(n)*squaring(n)==n;   
}
int count_divisor(int n){
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if((n%i)==0){
            cnt++;
        }
    }
    return cnt;
}
bool check5(int n){
    // no of divisor = odd
    // count all divisors

    if(count_divisor(n)%2!=0){
        return true;
    }
    return false;
}bool check6(int n){
    // sum of all odd natural number is square of that number

//    int sum = 1;
//    int total_sum = 1;
//    int cnt = n-1;
//    while(cnt--){
//     sum+=2;
//     total_sum+=sum;

//    }cout<<endl;
//    cout<<total_sum<<endl;

//    return n*n==total_sum;
 int sum = 1;
    int total_sum = 1;
    int cnt = n - 1;

    // Sum the odd natural numbers until total_sum >= n
    while (total_sum < n) {
        sum += 2;          // Increment to the next odd number
        total_sum += sum;  // Accumulate the sum of odd numbers
    }

    // Check if n is equal to total_sum (which should be the square of some number)
    return total_sum == n;
}
int main()
{
    clock_t tStart = clock();
    int n;
    cin>>n;

    if(check1(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
     if(check2(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
     if(check3(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
     if(check4(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
     if(check5(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    } if(check6(n)){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}