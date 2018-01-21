/**
Reverse Words in a String III ::
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving
whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
**/

/*class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int n = s.length();
        stringstream ss(s);
        string ans("");
        while(ss>>s)
        {
            reverse(s.begin(), s.end());
                 ans+=s+' ';
        }

    return ans.substr(0, n);
    }
};*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;
        int n = s.length();
        string ans("");
        int last = 0;
        for(int i=0; i<n; ++i){
            if(s[i]==' '){
                string str = s.substr(last, i-last);
                reverse(str.begin(), str.end());
                ans += str + ' ';
                last = i+1;
            }
        }
        string str = s.substr(last, n-last);
        reverse(str.begin(), str.end());
                ans += str;
      return ans;
    }
};


class Solution {
public:
    string rev(string x)
    {
        reverse(x.begin(), x.end());
        return x;
    }
    string reverseWords(string s) {
        string t, ans;
        for(char c: s)
        {
            if(c == ' ')
            {
                ans += rev(t) + ' ';
                t = "";
            }
            else
                t += c;
        }
        ans += rev(t);
        return ans;
    }
};



class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ret = "";
        while (ss >> s) {
            if (ret.size()) ret += " ";
            ret += string(s.rbegin(), s.rend());
        }
        return ret;
    }
};



class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        for (int i=0; i<s.length(); i++)
        if (s[i]==' '){
            reverse(s.begin()+start, s.begin()+i);
            start = i+1;
        }
        reverse(s.begin()+start, s.end());
        return s;
    }
};
