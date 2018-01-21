/*763. Partition Labels ::
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/


/*
class Solution {
public:
    vector<int> partitionLabels(string s) {
        bool visited[26];
        memset(visited, false, sizeof visited);
        int start = 0, last = 0;
        vector<int> ans;
        int n = s.size();
        for(int i=0; i<n; ++i){
            if(last == n-1){
                ans.push_back(n-1-start+1);
                break;
            }
            if(visited[s[i]-'a']){
                if(i==last){
                    ans.push_back(last-start+1);
                    start = last+1;
                    last = start;
                }
                continue;
            }
            
            visited[s[i]-'a'] = true;
            int j = n-1;
            while(j>last){
                if(s[i] == s[j]){
                    last = j;
                    break;
                }
                --j;
            }
             if(last == i){
                ans.push_back(1);
                start = last+1;
                last = start;
            }
        }
       return ans; 
    }
};*/



/*
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> cntall(26, 0);
        for (auto c : S) ++cntall[c-'a'];
        
        vector<int> ans;
        vector<int> cntnow(26, 0);
        int start = 0;
        for (int end=0; end<S.size(); ++end) {
            ++cntnow[S[end]-'a'];
            bool valid = true;
            for (int i=0; i<26; ++i)
                if (cntnow[i]!=0 && cntnow[i]!=cntall[i]) {
                    valid = false;
                    break;
                }
            
            if (valid) {
                ans.push_back(end-start+1);
                fill(cntnow.begin(), cntnow.end(), 0);
                start = end+1;
            }
        }
        return ans;
    }
};*/



/*
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, vector<int>> occurence;
        int n = 0;
        for(const auto& c : S)
        {
            occurence[c].push_back(n++);
        }
        int current_begin = 0;
        int current_end = 0;
        vector<int> ans;
        for(int i = 0; i < S.size(); i++)
        {
            if (i > current_end)
            {
                ans.push_back(current_end - current_begin + 1);
                current_begin = i;
                current_end = i;
            }
            current_end = max(current_end, occurence[S[i]].back());
        }
        ans.push_back(current_end - current_begin + 1);
        return ans;
    }
};*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        for (int i=0; i<S.size(); i++) last[S[i]-'a']=i;
        vector<int> parts;
        int i=0;
        while (i<S.size()) {
            int j=last[S[i]-'a'];
            for (int k=i; k<=j; k++)
                if (j<last[S[k]-'a']) j=last[S[k]-'a'];
            parts.push_back(j-i+1);
            i=j+1;
        }
        return parts;
    }
};


/*
//Java
class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> result = new LinkedList<Integer>();
        partitionLabels(S, 0, result);
        return result;
    }

    private void partitionLabels(String s, int start, List<Integer> result) {
        int n = s.length();
        if (start >= n) return;
        int end = start;
        int curr = start;
        while (curr <= end) {
            char ch = s.charAt(curr);
            int last = s.lastIndexOf(ch);
            if (last > end) {
                end = last;
            }
            curr++;
        }
        result.add(end - start + 1);
        partitionLabels(s, end + 1, result);
    }
}
*/

class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> result = new LinkedList<Integer>();
        partitionLabels(S, 0, result);
        return result;
    }

    private void partitionLabels(String s, int start, List<Integer> result) {
        int n = s.length();
        if (start >= n) return;
        int end = start;
        int curr = start;
        while (curr <= end) {
            char ch = s.charAt(curr);
            int last = s.lastIndexOf(ch);
            if (last > end) {
                end = last;
            }
            curr++;
        }
        result.add(end - start + 1);
        partitionLabels(s, end + 1, result);
    }
}