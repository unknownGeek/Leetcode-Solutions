/**
500. Keyboard Row ::
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
**/


//Version 1::
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string l1, l2, l3;
        l1 = "qwertyuiop";
        l2 = "asdfghjkl";
        l3 = "zxcvbnm";
        auto check = [&] (string s) {
            for (auto &c : s) {
                c = tolower(c);
            }
            for (const auto &l : {l1, l2, l3}) {
                bool ok = true;
                for (auto c : s) {
                    int i;
                    for (i = 0; i < l.size(); i++) {
                        if (l[i] == c)
                            break;
                    }
                    if (i == l.size()) {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                   return true;
            }
            return false;

        };
        vector<string> ans;
        for (const auto &word : words) {
            if (check(word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};



//Version 2 ::


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        auto check = [&] (string word, string row) {
                bool ok = true;
                for (auto &c : word) {
                    int i;
                    c = tolower(c);
                    for (i = 0; i < row.size(); i++) {
                        if (row[i] == c)
                            break;
                    }
                    if (i == row.size()) {
                        ok = false;
                        break;
                    }
                }
                return ok;
        };
        vector<string> ans;
        for ( auto word : words) {
            for( auto row : {"qwertyuiop", "asdfghjkl", "zxcvbnm"})
              if (check(word, row)){
                ans.push_back(word);
                  break;
            }
        }
        return ans;
    }
};
