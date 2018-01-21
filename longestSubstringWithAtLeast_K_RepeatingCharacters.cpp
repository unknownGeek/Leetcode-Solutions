/**
395. Longest Substring with At Least K Repeating Characters ::
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in
T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
**/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty())return 0;
        int n = s.length();
        if(n<k)return 0;
        int freq[26] = {0};
        for(char ch : s)
             ++freq[ch - 'a'];
        int i;
        for(i=0; i<n; ++i)
            if(freq[s[i] - 'a'] < k)
                 break;
        if(i<n)
             return max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i+1, n-i-1), k));
        return n;
    }
};
