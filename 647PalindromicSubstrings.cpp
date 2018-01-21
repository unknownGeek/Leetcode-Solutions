/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())return 0;
        int n = s.length();
        if(n==0 || n==1)return n;
        int ans=0;
        //count odd palindromes
        for(int i=0; i<n; ++i)
        {
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r])
                  --l, ++r;
            l++, --r;
            ans+= r - i + 1;
        }

        //count even palindromes
        for(int i=0; i<n-1; ++i)
        {
            if(s[i]!=s[i+1])
                 continue;
            int l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
                  --l, ++r;
            l++, --r;
            ans+= r - (i+1) + 1;
        }
        return ans;
    }
};
