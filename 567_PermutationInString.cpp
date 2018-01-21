/**
567. Permutation in String ::
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of
the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
**/

/*class Solution {
public:
    bool checkInclusion(string t, string s) {
        int m = t.length(), n = s.length();
        if (m > n) return false;
        vector<int> cnt(26);
        for (int i = 0; i < m; ++i) {
            cnt[t[i] - 'a']++;
        }
        vector<int> cur(26);
        for (int i = 0; i < m; ++i) {
            cur[s[i] -  'a']++;
        }
        if (cur == cnt) return true;
        for (int k = 1; k + m <= n; ++k) {
            cur[s[k - 1] - 'a']--;
            cur[s[k + m - 1] - 'a']++;
            if (cur == cnt) return true;
        }
        return false;

    }
};*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp;
        for (char c : s1) mp[c]++;
        int n1 = s1.size();
        int n2 = s2.size();
        for (int i = 0; i < n2; i++) {
            mp[s2[i]]--;
            if (i >= n1) mp[s2[i - n1]]++;
            bool ok = 1;
            for (auto j : mp) ok &= j.second == 0;
            if (ok) return 1;
        }
        return 0;
    }
};
