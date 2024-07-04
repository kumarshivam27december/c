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
}bool check5(int n){
    // no of divisor = odd
    int cnt = 0;
    for(int i = 1;i<n;i++){
        if(n%i==0){
            cnt++;
        }
    }

    return cnt%2!=0;
}bool check6(int n){
    // sum of all odd natural number is square of that number

    int sum = 0;
    for(int i = 1;i<=n;i+=2){
        sum+=i;
    }

    return sqrt(sum)==n;
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