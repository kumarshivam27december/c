/*
1
5 3
2 1 7 4 2

we have 3 min and length of array is 5

in 1st min eat 7 and then add 7/2 = 3 to it
array become
2 1 3 4 2

in 2nd minute eat 4 and then add 4/2 = 2 to it
array become
2 1 3 2 2

in last minute we can eat 3 candi and add 3/2 to it
array become
2 1 1 2 2 

now no min left
and total candy we have eaten is 7+4+3 = 14


we will use multiset because in test case more than 1 time an element could
be come in a string

*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int sizes;
        cin>>sizes;
        int times;
        cin>>times;
        multiset<long long>bags;
        for(int i = 0;i<sizes;++i){
            long long num;
            cin>>num;
            bags.insert(num);
        }
        long long total_candies = 0;
        while(times--){
                multiset<long long>:: iterator it = --bags.end();
                
                long long last_candy = *it;
                total_candies+=last_candy;
                bags.erase(it);
                bags.insert(last_candy/2);
        }
        cout<<"Total candies is "<<total_candies<<endl;

    }
    return 0;
}