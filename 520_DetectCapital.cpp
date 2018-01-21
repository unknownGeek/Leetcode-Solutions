/**
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
**/
//Version 1::
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.empty())return false;
        int n = word.length();
        if(n==1)return true;
        if('A'<=word[0] && word[0]<='Z'){
            if('A'<=word[1] && word[1]<='Z'){
                 for(int i=2; i<n; ++i)
                    if(!('A'<=word[i] && word[i]<='Z'))return false;
                return true;
            }
            else if('a'<=word[1] && word[1]<='z'){
                for(int i=2; i<n; ++i)
                    if(!('a'<=word[i] && word[i]<='z'))return false;
                return true;
            }
            else
                return false;
        }
        else if('a'<=word[0] && word[0]<='z'){
            for(char ch : word)
                if(!('a'<=ch && ch<='z'))return false;
            return true;
        }
        else
            return false;
    }
};


// Version 2::
class Solution {
public:
    bool detectCapitalUse(string word) {
        int u = 0, l = 0;
        for (auto &c : word)
            if (c >= 'A' && c <= 'Z') u++;
            else l++;
        if (u == 0 || l == 0) return true;
        if (u == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;

        return false;
    }
};
