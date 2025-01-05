#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr = {3,4,2,1,9,8};
    int Arr[] = {2,1,3,4,7,6};

    sort(arr.begin()+1,arr.end()); //sort from 2nd element to the last element
    sort(arr.begin(),arr.end()); // sort all the array

    sort(Arr,Arr+3);//sort first three element
    sort(Arr,Arr+6);// sort all the array

    return 0;
}