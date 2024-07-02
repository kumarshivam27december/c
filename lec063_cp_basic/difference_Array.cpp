// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int size;
//     cin>>size;
//     vector<int>arr(size);
//     for(int i = 0;i<size;i++){
//         cin>>arr[i];
//     }
//     int t;cin>>t;
//     while(t--){
//         int start,end,num;
//         cin>>start>>end>>num;
//         for(int i = start;i<=end;i++){
//             arr[i]+=num;
//         }
//     }
//     for(auto i : arr){
//         cout<<i<<" ";
//     }cout<<endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

//     // Create a difference array initialized to 0
//     vector<int> diff(size + 1, 0);

//     int t;
//     cin >> t;
//     while (t--) {
//         int start, end, num;
//         cin >> start >> end >> num;
//         diff[start] += num;
//         if (end + 1 < size) {
//             diff[end + 1] -= num;
//         }
//     }

//     // Apply the difference array to the original array
//     int current_add = 0;
//     for (int i = 0; i < size; i++) {
//         current_add += diff[i];
//         arr[i] += current_add;
//     }

//     for (auto i : arr) {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
// }



// // difference array 


        // creating the difference array
        vector<int>difference_array(size+1,0);


        int q;
        cin>>q;
        while(q--){
            int start,end,num;
            cin>>start>>end>>num;
            difference_array[start]+=num;
            if(end+1<size){
                difference_array[end]-=num;
            }
        }

        int current_add = 0;
        for(int i = 0;i<size;i++){
            current_add+=difference_array[i];
            arr[i]+=current_add;
        }
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
}