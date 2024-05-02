#include <bits/stdc++.h>
#include <time.h>
using namespace std;
 string reversePrefix(string word, char ch) {
        int inx = -1;
        for(int i = 0;i<word.size();i++){
            if(word[i]==ch){
                inx = i;
                break;
            }
        }
        int k = 0;
        int l = inx;
        while(k<l){
            swap(word[k],word[l]);
            k++;
            l--;
        }

        return word;
    }
int main()
{
    clock_t tStart = clock();
    string word = "abcdefd";
    char ch = 'd';
    string ans = reversePrefix(word,ch);
    cout<<ans;
    cout<<endl;
    printf("Time taken: %.2fms", (double)(clock() - tStart)/(CLOCKS_PER_SEC/1000000));
    cout<<endl;
    return 0;
}