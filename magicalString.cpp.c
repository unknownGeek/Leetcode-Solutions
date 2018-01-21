/**
481. Magical String ::
A magical string S consists of only '1' and '2' and obeys the following rules:

The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the
string S itself.

The first few elements of string S is the following: S = "1221121221221121122……"

If we group the consecutive '1's and '2's in S, it will be:

1 22 11 2 1 22 1 22 11 2 11 22 ......

and the occurrences of '1's or '2's in each group are:

1 2	2 1 1 2 1 2 2 1 2 2 ......

You can see that the occurrence sequence above is the S itself.

Given an integer N as input, return the number of '1's in the first N number in the magical string S.

Note: N will not exceed 100,000.

Example 1:
Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
**/

//Version 1 ::
class Solution {
public:
    int magicalString(int n) {
        string s("122");
        for(int i=2; i<n; ++i){
            char val = i&1 ? '2' : '1';
            for(int j=0; j<s[i]-'0'; ++j)
                 s+=val;
        }
        int ans = 0;
        for(int i=0; i<n; ++i)
            ans += (s[i] == '1');
        return ans;
    }
};

//Version 2 ::
class Solution {
public:
    int magicalString(int n) {
        vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(2);
        for (int i = 2; i < n; i++) {
            int val = (i & 1) ? 2 : 1;
            for (int j = 0; j < a[i]; j++)
                a.push_back(val);
        }
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] == 1;
        }
        return ans;
    }
};

