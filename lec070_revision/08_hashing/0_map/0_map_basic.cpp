#include <bits/stdc++.h>
using namespace std;
void printmap(map<int,string>&mp){
    cout<<mp.size()<<endl;
    // for(auto &it: mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    map<int,string> ::iterator it;
    for(it = mp.begin();it!=mp.end();++it){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}
int main() {
    map<int,string>mp;// made using red black tree data structure which is self balancing tree
    //stored in sorted order or lexiography increasing order
    //can't store dublicate key it will update the value only
    //declaring key will also lead to logn complexity
    //insertion in map in done in logn complexity
    //accessing element complexity is logn 
    //inside loop to traverse all the insertion time complexity is nlogn and the accessing the element from the loop or traversing them the time complexity is also nlogn 

    mp[1]="abc";
    mp[2]="def";
    mp[3] = "ghij";
    mp[4] = "klmn";

    printmap(mp);

    //mp.find(3);//this is logn complexity to find 
    //find return an iterator
    auto it = mp.find(3);
    if(it!=mp.end()){
        cout<<"element is found"<<endl;
        cout<<((*it).first)<<" "<<((*it).second)<<endl;
    }else{
        cout<<"element not found";
    }

    //can take two argument that is iterator as well as the key
    mp.erase(it);//this is iterator will find the pair and then delete it 
    mp.erase(5);//do the same work
    //in both case mp.erase take the time complexity of log(n)

    //if inside erase function any such value is to deleted which is not present
    //then it will cause segmentation fault

    //it should be valid iterator which exists in the map

    // so instead we use a check for it
    it = mp.find(3);//we reinstialise it because it was erased from the map
    if(it!=mp.end()){
        mp.erase(it);
    }
    printmap(mp);


    mp.clear();//work almost in all stl clear all the map 
    printmap(mp);



    //now if the key is string the inserting time complexity is not only logn but now since it is being made in red black tree data structure it basically compare it with other element or string present in the tree to find the position where to insert it comparing the key which is string with the other string takes the t.c of O(str.size()) so now total time complexity will be O(str.size()(logn)

    return 0;
}