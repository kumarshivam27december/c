#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        string str;
        cin >> str;
        int size = str.length();
        if (size <= 10)
        {
            cout << str << endl;
        }else{
            string ans = "";
            ans+=str[0];
            string num = to_string(size-2);
            ans+=num;
            char t = str[size-1];
            ans+=t;
            cout<<ans<<endl;
        }
        
    }
    return 0;
}