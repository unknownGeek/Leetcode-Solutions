/**
677. Map Sum Pairs ::
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
**/

class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> hash;
    MapSum() {

    }

    void insert(string key, int val) {
        auto it = hash.find(key);
        if(it == hash.end()){
            hash[key] = val;
        }
        else{
            it->second = val;
        }

    }

    int sum(string prefix) {
        int ans = 0;
        int n = prefix.length();
        for(auto it : hash){
            string str = it.first.substr(0, n);
            if(str == prefix)
                 ans += it.second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
