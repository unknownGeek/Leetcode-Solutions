/**
License Key Formatting ::
Now you are given a string S, which represents a software license key which we would like to format. The string S is composed
of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups.
(i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.

We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must
contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters
in the string must be converted to upper case.

So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license
key formatted according to the description above.

Example 1:
Input: S = "2-4A0r7-4k", K = 4

Output: "24A0-R74K"

Explanation: The string S has been split into two parts, each part has 4 characters.
Example 2:
Input: S = "2-4A0r7-4k", K = 3

Output: "24-A0R-74K"

Explanation: The string S has been split into three parts, each part has 3 characters except the first part as it could be shorter
as said above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.
**/

// Version 1::
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str("");
        int n = s.size();
        for(int i=n-1; i>=0; --i){
            if(s[i] != '-'){
                if('a' <= s[i] && s[i]<='z')
                    s[i] -= 32;
                str+=s[i];
            }
        }
        n = str.length();
        string ans("");
        int i=0, j=0;
        while(i<n){
            while(j<n && j-i<k){
                ans += str[j];
                ++j;
            }
            i=j;
           if(i!=n)
                ans+='-';
        }
        //cout<<ans;
        reverse(ans.begin(), ans.end());
        return ans;

    }
};


//Version 2::
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s = "";
        for (auto ch : S) {
            if (ch == '-') continue;
            if (islower(ch)) {
                s = s + (char)(ch - 'a' + 'A');
            }
            else
                s = s + ch;
        }
        vector<string> cur;
        while (s.length() > K) {
            int len = s.length();
            string sub = s.substr(len - K);
            cur.push_back(sub);
            s = s.substr(0, len - K);
        }
        string ans = "";
        for (string word : cur)
            ans = "-" + word + ans;
        ans = s + ans;
        return ans;
    }
};

//Version 3 ::
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s2 = "";
        for(int i=0; i<S.size(); ++i){
            if('a'<=S[i] && S[i]<='z') S[i]+='A'-'a';
            if(S[i]!='-') s2+=S[i];
        }
        int len=s2.size();
        string res="";
        for(int j=len-1; j>=0; --j){
            res = s2[j] + res;
            if(j>0 && (len-j)%K==0) res="-"+res;
        }
        return res;
    }
};
