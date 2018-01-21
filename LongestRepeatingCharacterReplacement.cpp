/**
424. Longest Repeating Character Replacement ::
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter
at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above
operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
**/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int maxlen = 0;
        for (int i = 0; i < len; ++i) {
            if (i != 0 && s[i] == s[i-1]) continue;
            char currLetter = s[i];
            int cnt = k;
            int j;
            for (j = i+1; j < len; ++j) {
                if (s[j] != currLetter) --cnt;
                if (cnt < 0) break;
            }
            int xxx = j-i;
            if(cnt>=0){
            for (j = i-1; j>=0; --j) {
                if (s[j] != currLetter) --cnt;
                if (cnt < 0) break;
             }
                xxx += i-j-1;
            }
            maxlen = max(maxlen, xxx);
        }
        return maxlen;
    }
};
