#include <iostream>
using namespace std;
int main()
{
    // << this is left shift
    cout<<(5<<2)<<endl;
    // this shift bit of 5 two times
    // we can also do multiplication by 2 to the power of right 
    //i.e. 5*(2^2)

    cout<<(17<<1)<<endl;
    // this is (17*(2^1)) = 34
    //this always not work for very very big number the number become +ve to -ve


    //  >> this is right shift
    cout<<(5>>2)<<endl;
    // this is equal to (5/2^2)
    cout<<(6>>1)<<endl;
    // this is equal to (6/2^1)
    


}