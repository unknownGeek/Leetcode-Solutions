/**
Concatenated Words ::
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
**/

//Version 1 ::
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        for (string const& word : words)
            dict.insert(word);
        sort(words.begin(), words.end(), [](string const& a, string const& b){
            if (a.size() != b.size()) return a.size() < b.size();
            return a < b;
        });
        unordered_map<string, bool> cache;

        function<bool(const string&)> check;
        check = [&](const string& str) {
            if (cache.count(str)) {
                return cache[str];
            }
            for (int i = 1; i < str.size(); i++) {
                string a = str.substr(0, i);
                if (dict.count(a) == 0) continue;
                string b = str.substr(i);
                bool result = dict.count(b) ? true : cache.count(b) ? cache[b] : check(b);
                if (result) return cache[str] = true;
            }
            return cache[str] = false;
        };

        vector<string> result;
        for (string const& str : words)
            if (check(str))
                result.push_back(str);
        return result;
    }
};



//Version 2 ::
class Solution {
public:
    unordered_set<string> set;
    string s;
    bool ans;
    void dfs(string::iterator now)
    {
        if (now==s.end())
        {
            ans=true;
            return;
        }
        string t;
        for (string::iterator it=now;it!=s.end();it++)
        {
            if (now==s.begin()&&it==s.end()-1) return;
            t.push_back(*it);
            if (set.find(t)!=set.end())
            {
                dfs(it+1);
                if (ans) return;
            }
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> words)
    {
        for (string x:words)
            set.insert(x);
        vector<string> res;
        for (string x:words)
        {
            s=x;ans=false;
            if (s.empty()) continue;
            dfs(s.begin());
            if (ans) res.push_back(s);
        }
        return res;
    }
};
