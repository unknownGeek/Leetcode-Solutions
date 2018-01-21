/**
Reverse String II ::
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the
start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater
than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
**/


//Version 1::
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        for (int i = 0; i < n; i += k<<1) {
            int v = min<int>(n, i + k);
            reverse(s.begin() + i, s.begin() + v);
        }
        return s;
    }
};


//Version 2::
class Solution {
public:
    string reverse(string s)
    {
        string ans = "";
        for (char c : s)
            ans = c + ans;
        return ans;
    }
    string reverseStr(string s, int k) {
        if (s.size() > k*2)
            return reverseStr(s.substr(0,k*2),k)+reverseStr(s.substr(k*2,s.size()-k*2),k);
        if (s.size() == k*2)
            return reverse(s.substr(0,k))+s.substr(k,k);
        if (s.size() <= k)
            return reverse(s);
        return reverse(s.substr(0,k))+s.substr(k,s.size()-k);
    }
};
