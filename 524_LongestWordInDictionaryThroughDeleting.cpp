/**
524. Longest Word in Dictionary through Deleting ::
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some
characters of the given string. If there are more than one possible results, return the longest word with the smallest
lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.
**/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        if(d.empty())return string("");
        sort(d.begin(), d.end(), [](string const& a, string const& b){
            if(a.length() != b.length())return a.length()>b.length();
            return a<b;
        });

        function<bool(string)> check;
        check = [&] (string str){
            int freq[26]={0};
            for(char &ch : s)
               ++freq[ch-'a'];
            for(char &ch : str){
                if(freq[ch-'a'])
                    --freq[ch-'a'];
                else
                    return false;
                return true;
            }
        };
        function<bool(string)> subsequence;
        subsequence = [&] (string str){
          int i=0, j=0;
            int n=s.size();
            int m=str.size();
            while(i<n && j<m){
                if(s[i]==str[j])
                    ++j;
                ++i;
            }
            return j==m;
        };
        for(string &str : d)
            if(check(str) && subsequence(str))return string(str);
        return string("");
    }
};
