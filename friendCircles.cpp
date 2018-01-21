/**
Friend Circles ::
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined
a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and
jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles
among all the students.

Example 1:
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
**/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())return 0;
        int n = M.size();
        int m = M[0].size();
        unordered_map<int, int> father;
        for(int i=0; i<n; ++i)
              father[i] = i;
        function<int(int)> find;
        find = [&] (int x){
            return x==father[x] ? x : father[x] = find(father[x]);
        };
        function<void(int, int)> _union;
        _union = [&] (int i, int j){
                int p_i = find(i);
                int p_j = find(j);
                if(p_i!=p_j)
                    father[p_i] = p_j;
            };
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i>=j || !M[i][j])continue;
                int p_i = find(i);
                int p_j = find(j);
                if(p_i != p_j){
                    _union(p_i, p_j);
                }
            }
        }
        set<int> s;
        for(auto pair : father)
            s.insert(find(pair.second));
        return s.size();
    }
};



class Solution {
public:
    vector<int> p;
    int n;
    int FIND(int x) {
        return p[x]==x? p[x]: p[x]=FIND(p[x]);
    }
    void UNION(int x, int y) {
        p[FIND(x)] = FIND(y);
    }
    int findCircleNum(vector<vector<int>>& M) {
        p = vector<int>();
        n = M[0].size();
        for(int i=0;i<n;i++) p.push_back(i);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) if(M[i][j]==1) UNION(i, j);
        int cnt=0;
        for(int i=0;i<n;i++)
        if(FIND(i) == i) ++cnt;
        return cnt;
    }
};




class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = (int)M.size();
        int ans = 0;
        vector<bool> vis(n, false);
        for (int i=0; i<n; ++i) {
            if (vis[i]) continue;
            ++ans;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int front = q.front();
                vis[front] = true;
                q.pop();
                vis[i] = true;
                for (int j=0; j<n; ++j) {
                    if (M[front][j] == 1 && !vis[j]) {
                        q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    void dfs(int curr, vector<bool>& visited, vector<vector<int>>& M) {
        visited[curr] = true;
        for (int i = 0; i < M.size(); i++) {
            if (!visited[i] && M[curr][i] == 1) {
                dfs(i, visited, M);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if (N == 0) {
            return 0;
        }
        vector<bool> visited(N, false);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, visited, M);
            }
        }
        return ans;
    }
};
