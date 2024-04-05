#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_dublicate(vector<int> &v){
    int i = 1;
    for(int j = 1;j<v.size();j++){
        if(v[j]!=v[j-1]){
            v[i] = v[j];
            i++;
        }
    }
    return i;
//    int i = 0;
//    for(int j = 1;j<v.size();j++){
//     if(v[i]!=v[j]){
//         i++;
//         v[i]=v[j];
//     }
//    }
//    return i+1;

}
int main(){
    vector<int> v = {0,0,1,1,1,2,2};
    clock_t tStart = clock();
    int ans = remove_dublicate(v);
    for(int i = 0;i<ans;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
    return 0;
}


/*

set<int> s;
    for(int i =0;i<v.size();i++){
        s.insert(v[i]);
    }                                              
    v.clear();
    for(auto i:s){
        v.push_back(i);
    }
    return v.size();


    Time complexity -> 0(nlogn+n+n+1) i.e n(nlogn)
    space complexity -> O(n)

*/



/*

 int i = 0;
    while (i<v.size()-1)
    {
        if(v[i]==v[i+1]){
            v.erase(v.begin()+i);
        }else{
            i++;
        }
    }
    return v.size();

    space complexity -> O(1)
    Time complexity->O(n*n)


*/
