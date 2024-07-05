// range of modules is 0 to m-1 if(a%m)


// always add m if the number is negative before (a+m)%m,

//properties of modules


// (a+b)%m = (a%m+b%m)%m
//(a-b)%m = (a%m-b%m+m)%m
// (axb)%m = (a%m * b%m)%m
// (a/b)%m = (a%m/b%m)%m; ---not possible

// (a/b)%m
// when m is prime number
// (a*b^-1)%m
// modulo multiplicative inverse
// 1e9 not prime and 1e9+7 is prime because only possible in prime case only such that we dont use extended gcd
// for b inverse we can find it by
// b^-1 = pow(b,m-2);
// power nikalte hai using binary exponential;
// b^-1 != (1/b) --why ?


#include <iostream>
using namespace std;
int power(int a,int b){

   int mul = 1;
   while(b--){
    mul*=a;
   }
   return mul;
}
int main(){
    // cout<<(4-3)%5;cout<<endl;
    // cout<<(4+3)%5;cout<<endl;
    // cout<<(3-4)%5;cout<<endl;
    // cout<<(3*4)%5;cout<<endl;
    // cout<<(3/4)%5;cout<<endl;
    // cout<<(3/3)%5;
    int a = 3;
    int b = 5;
    int m = 7;
    int c = power(b,m-2)%m;
    cout<<(a*c)%m<<endl;
    return 0;

}
