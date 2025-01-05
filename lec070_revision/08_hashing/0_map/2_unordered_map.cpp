#include <bits/stdc++.h>
using namespace std;
void printumap(unordered_map<int,string>&umap){
    cout<<"The size of the unordered_map is "<<umap.size()<<endl;
    unordered_map<int,string> :: iterator it;
    for(it = umap.begin(); it!= umap.end();++it){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}
int main() {
    //difference between map and unordered map is 
    //1.inbuilt implementation
    //2.time complexity
    //3.valid key datatypes

    //rest all the functions are same as map

    unordered_map<int,string>umap;

    //in this hashtable is made instead of tree (which was in red black tree in case of map) 
    //time complexity insertion O(1) and accessing O(1) which is average time complexity because sometime due to collision handling or internal  collision it can take more time




    //map on comparison basis work but unordered map work on hash now pair does not have any inbuild defined  hash function so we cannot take pair as a key in unordered map but in case of map we can take it as we can compare two pairs and then insert it


    //in which direct comparison is possible we can use map

    // and in unordered map in which inbuild hash function is not defined we cannot use it as key 


    return 0;
}