/*
767. Reorganize String ::
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

//debugging snippets
#define debug(x)        cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<"\n";
#define debug2(x, y)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<"\n";
#define debug3(x, y, z)  cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<"\n";
#define debug4(x, y, z ,w)  cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<" | "#w" ="<<w<<"\n";
 
 
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int freq[26];
        memset(freq, 0, sizeof freq);
        for(char &ch : s){
            ++freq[ch - 'a'];
        }
        for(int i=0; i<26; ++i){
            if(freq[i] >= (n+3)>>1){
                return string("");
            }
        }
        sort(s.begin(), s.end(), [&] (char const& a, char const& b){
           return freq[a-'a']!=freq[b-'a'] ? freq[a-'a']>freq[b-'a'] : a<b; 
        });
        cout<<s;
        string ans(n, ' ');
        int idx = 0;
        for(int i=0; i<n; ++i){
            while(freq[s[i]-'a']  --> 0){
                ans[idx] = s[i];
                idx += 2;
                if(idx >= n){
                    idx = 1;
                }
            }
        }
        return ans;
    }
};