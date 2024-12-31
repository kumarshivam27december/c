/*
check to two point are given l and r
between them of a string that 
a palindrome can be made or not

aabbck 
1 3
// abb   bab
so the logic is if there is count of odd more than one
then it can never be palindrome as palindrome as even no of
digits as it has to appear twice that is to the left of the 
centre element and to the right of the middle element

first try the brute force approach


#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string str;
        cin>>str;
        while(q--){
            int l,r;
            cin>>l>>r;
            int hash[26];
             
            for(int i = 0;i<26;i++){
                hash[i]=0;
            }

            l--;
            r--;
            for(int i = l;i<=r;i++){
                hash[str[i]-'a']++;
            }

            int oddcount = 0;
            for(int i = 0;i<26;i++){
                if(hash[i]%2){
                    oddcount++;
                }
            }

            if(oddcount>1){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int hashing[N][26];
int main() {
    int t;
    cin>>t;
    while(t--){
        //we initialise hashing each time with zero
        for(int i = 0;i<N;i++){
            for(int j = 0;j<26;j++){
                hashing[i][j]=0;
            }
        }

        int n,q;
        cin>>n>>q;
        string str;
        cin>>str;

        // just fill har position pe wo wo element kitti baar aa rha hai
        for(int i = 0;i<n;i++){
            hashing[i+1][str[i]-'a']++;
        }

        //i+1 prefix array me a to z ko store kiye hai kitti bar aaya hai
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<26;j++){
                hashing[i][j]=hashing[i-1][j];
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int oddcnt = 0;
            for(int j = 0;j<26;j++){

                // calculate kar rhe hai ki right -(left-1) of a to z yani 0 to 25
                int charcnt = hashing[r][j]-hashing[l-1][j];
                if(charcnt%2!=0) oddcnt++;
            }
            if(oddcnt>1){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
/*
Let's break down the explanation **step by step** and clarify things with a more structured approach. We'll focus on the example `"abaccde"`, and go step by step to explain how the prefix sum array works and how queries are processed.

---

### **Step 1: Understand the Purpose**

The goal is to:
1. **Preprocess** the string to efficiently calculate how many times each character ('a' to 'z') appears in any substring `[l, r]`.
2. **Answer queries**: Determine if a substring can be rearranged into a palindrome. 
   - A string can be rearranged into a palindrome if at most **one character has an odd count**.

---

### **Step 2: Initializing the Prefix Array (`hashing`)**

1. **What is `hashing[i][j]`?**
   - It stores the **cumulative count of character `j` ('a' to 'z')** in the first `i` characters of the string.

2. Example:
   - If the string is `"abaccde"`, `hashing[3][0]` will tell how many times `'a'` appears in the first 3 characters (`"aba"`).

3. Dimensions:
   - `hashing` is a 2D array of size `[n+1][26]` (7+1 rows for string length + 1, 26 columns for 'a' to 'z').

---

### **Step 3: Building the Prefix Array**

The code snippet:

```cpp
for (int i = 0; i < n; i++) {
    hashing[i + 1][str[i] - 'a']++;  // Increment current character frequency
    for (int j = 0; j < 26; j++) {
        hashing[i + 1][j] += hashing[i][j];  // Add previous prefix sums
    }
}
```

This does two things:
1. For the current character `str[i]`, increment its frequency at position `i+1` in `hashing`.
2. Carry forward the cumulative counts from the previous position (`i`).

---

#### **Walkthrough for `"abaccde"`**

| **Index (i)** | **Character** | **str[i] - 'a'** | `hashing[i+1]` Before Update | `hashing[i+1]` After Update (Cumulative Sum) |
|---------------|---------------|------------------|-----------------------------|---------------------------------------------|
| 0             | `'a'`         | 0                | `[0, 0, 0, ...]`             | `[1, 0, 0, 0, ...]`                         |
| 1             | `'b'`         | 1                | `[1, 0, 0, ...]`             | `[1, 1, 0, 0, ...]`                         |
| 2             | `'a'`         | 0                | `[1, 1, 0, ...]`             | `[2, 1, 0, 0, ...]`                         |
| 3             | `'c'`         | 2                | `[2, 1, 0, ...]`             | `[2, 1, 1, 0, ...]`                         |
| 4             | `'c'`         | 2                | `[2, 1, 1, 0, ...]`          | `[2, 1, 2, 0, ...]`                         |
| 5             | `'d'`         | 3                | `[2, 1, 2, 0, ...]`          | `[2, 1, 2, 1, ...]`                         |
| 6             | `'e'`         | 4                | `[2, 1, 2, 1, ...]`          | `[2, 1, 2, 1, 1, ...]`                      |

At the end, the `hashing` array contains the cumulative counts for each character at every position.

---

### **Step 4: Processing Queries**

To determine if a substring `[l, r]` can be rearranged into a palindrome:

1. Use the formula to get the count of each character in the range `[l, r]`:
   \[
   \text{count of char } j = \text{hashing}[r][j] - \text{hashing}[l-1][j]
   \]
   - This subtracts the cumulative count at position `l-1` from the cumulative count at `r`.

2. Count how many characters have an **odd frequency** in the substring.
   - If there is more than 1 character with an odd frequency → Output `"NO"`.
   - Otherwise → Output `"YES"`.

---

#### **Example Queries for `"abaccde"`**

**Prefix Array** (from Step 3):

| **Index** | **a** | **b** | **c** | **d** | **e** | ... |
|-----------|-------|-------|-------|-------|-------|-----|
| 0         | 0     | 0     | 0     | 0     | 0     | ... |
| 1         | 1     | 0     | 0     | 0     | 0     | ... |
| 2         | 1     | 1     | 0     | 0     | 0     | ... |
| 3         | 2     | 1     | 0     | 0     | 0     | ... |
| 4         | 2     | 1     | 1     | 0     | 0     | ... |
| 5         | 2     | 1     | 2     | 0     | 0     | ... |
| 6         | 2     | 1     | 2     | 1     | 0     | ... |
| 7         | 2     | 1     | 2     | 1     | 1     | ... |

---

#### Query 1: Substring `[2, 5]` (String = `"bacc"`)

1. Calculate character counts:
   - `'a'`: `hashing[5][0] - hashing[1][0] = 2 - 1 = 1`
   - `'b'`: `hashing[5][1] - hashing[1][1] = 1 - 0 = 1`
   - `'c'`: `hashing[5][2] - hashing[1][2] = 2 - 0 = 2`
   - Other characters: 0.

2. Odd frequencies:
   - `'a'`: Odd
   - `'b'`: Odd
   - `'c'`: Even

   → 2 odd frequencies → Output: `"NO"`

---

#### Query 2: Substring `[1, 7]` (String = `"abaccde"`)

1. Calculate character counts:
   - `'a'`: `hashing[7][0] - hashing[0][0] = 2 - 0 = 2`
   - `'b'`: `hashing[7][1] - hashing[0][1] = 1 - 0 = 1`
   - `'c'`: `hashing[7][2] - hashing[0][2] = 2 - 0 = 2`
   - `'d'`: `hashing[7][3] - hashing[0][3] = 1 - 0 = 1`
   - `'e'`: `hashing[7][4] - hashing[0][4] = 1 - 0 = 1`

2. Odd frequencies:
   - `'b'`, `'d'`, `'e'`: Odd

   → 3 odd frequencies → Output: `"NO"`

---

#### Query 3: Substring `[3, 6]` (String = `"accd"`)

1. Calculate character counts:
   - `'a'`: `hashing[6][0] - hashing[2][0] = 2 - 1 = 1`
   - `'b'`: `hashing[6][1] - hashing[2][1] = 1 - 1 = 0`
   - `'c'`: `hashing[6][2] - hashing[2][2] = 2 - 0 = 2`
   - `'d'`: `hashing[6][3] - hashing[2][3] = 1 - 0 = 1`

2. Odd frequencies:
   - `'a'`, `'d'`: Odd

   → 2 odd frequencies → Output: `"NO"`

---

### **Key Takeaways**

1. The prefix sum array allows quick computation of character frequencies in any substring.
2. Use the odd frequency count to decide if a substring can be rearranged into a palindrome.
3. The process involves:
   - Building the `hashing` array (\(O(n \times 26)\)).
   - Answering each query in \(O(26)\).

*/

// hackerearth submisssion
/*

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int hashing[N][26];
int main() {
	int s;
	cin>>s;
	string str;
	cin>>str;
	int n= str.size();
	for(int i = 0;i<n;i++){
		hashing[i+1][str[i]-'a']++;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<26;j++){
			hashing[i][j] += hashing[i-1][j];
		}
	}
	while(s--){
		int l,r;
		cin>>l>>r;
		int od = 0;

		for(int j = 0;j<26;j++){
			int oc = hashing[r][j]-hashing[l-1][j];
			if(oc%2!=0) od++;
		}
		if(od>1){
			cout<<"Impossible"<<endl;
		}else{
			cout<<"Possible"<<endl;
		}
	}
}
*/