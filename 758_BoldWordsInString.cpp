/*
758. Bold Words in String ::
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
*/
class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = words.size();
        int len = s.length();
        bool hit[len];
        memset(hit, false, sizeof hit);
        for(string &word : words){
            for(int i=0; i<len-word.length()+1; ++i){
                if(s.substr(i, word.length()) == word){
                    for(int j=0; j<word.length(); ++j){
                        hit[i+j]=true;
                    }    
                }
            }
        }
        
        string str("");
        for(int i=0; i<len; ++i){
            if(hit[i]){
                str = str + "_" + s[i] + "!"; 
            }else{
                str += s[i];
            }
        }
        cout<<str;
        len = str.length();
        string ans("");
        for(int i=0; i<len; ++i){
            if(i<len-1 && str[i]== '!' && str[i+1] == '_'){
                ++i;
                continue;
            }else if(str[i] == '_'){
                ans += "<b>";
            }else if(str[i] == '!'){
                ans += "</b>";
            }else{
                ans += str[i];
            }
        }
       return ans; 
    }
};



