#include <iostream>
#include <vector>
#include <string>
using namespace std;
void breakdigits(int n,vector <int>&ans)
{
    if(n==0)
    {
        return;
    }
    breakdigits(n/10,ans);
    ans.push_back(n%10);
}
void saydigits(vector<int> &digits,string arr[])
{
    for (int i = 0; i < digits.size(); i++)
    {
        cout<<arr[digits[i]-1]<<" ";

    }
    cout<<endl;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> digits;
    breakdigits(n,digits);
    string arr[10] = {"one","two","three","four","five","six","seven","eight","nine"};
    saydigits(digits,arr);
    return 0;
}