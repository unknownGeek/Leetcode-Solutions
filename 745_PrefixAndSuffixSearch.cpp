/*
745. Prefix and Suffix Search ::
Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1
Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.
*/


class WordFilter {
private:
    map<string, int> hash;
public:
    WordFilter(vector<string> words) {
        int n = words.size();
        for(int i=0; i<n; ++i){
            string &str = words[i];
            int len = str.length();
            for(int j=0; j<=len; ++j){
                string prefix = str.substr(0, j);
                for(int k=0; k<=len; ++k){
                    string suffix = str.substr(len - k, k);
                    int &weight = hash[prefix + "#" + suffix];
                    weight = max<int>(weight, i+1);
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return hash[prefix + "#" + suffix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */