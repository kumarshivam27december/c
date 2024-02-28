#include <iostream>
using namespace std;
bool checkpalindrome(string name,int i,int j)
{
    //base case
    if (i>j)
    {
        return true;
    }

    if (name[i]!=name[j])
    {
        return false;
    }
    else
    {
        //recursive call
        return checkpalindrome(name,i+1,j-1);
    }
}
int main()
{
    string name ="abbccbba";
    bool ispalindrome = checkpalindrome(name,0,name.length()-1);
    if (ispalindrome)
    {
        cout<<"its is palindrome "<<endl;
    }
    else
    {
        cout<<"its not is palindrome "<<endl;
    }
    
    return 0;
}