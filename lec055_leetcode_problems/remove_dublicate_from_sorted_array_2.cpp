#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int remove_dublicate(vector<int> &v){

    int i = 0;
    for (int num : v)
    {
        if(i<2 || num!=v[i-2]){
            v[i++] = num;
        }
    }
    
    
   return i;
}
int main()
{
    clock_t tStart = clock();
    vector<int> v = {0,0,0,1,1,1,2,2,3,3,3,4,4,5};
    int ans = remove_dublicate(v);
    for (int j = 0; j < ans; j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    return 0;
}


/*


 //find the left pointer 
    
    if(v.size()<=2) return v.size();
    int cow = 2;
    for(int j = 2;j<v.size();j++){
        
        if(v[j]!=v[j-2]){
            v[cow] = v[j];
            cow++;
        }
    }
    return cow;
*/