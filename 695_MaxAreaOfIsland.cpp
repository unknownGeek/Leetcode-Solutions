/**
695. Max Area of Island ::
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
**/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        const int dx[] = {1, -1, 0,  0};
        const int dy[] = {0,  0, 1, -1};
        function<int(int, int)> dfs;
        dfs = [&] (int x, int y) -> int {
            grid[x][y] = 0;
            int p=1;
            for(int i=0; i<4; ++i){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY])
                    p += dfs(newX, newY);
            }
            return p;
        };
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j])
                    ans = max<int>(ans, dfs(i, j));
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n, m;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]) {
                    queue<int> q;
                    q.push(i);
                    q.push(j);
                    grid[i][j] = 0;
                    const int dx[4] = {0, 1, 0, -1};
                    const int dy[4] = {1, 0, -1, 0};
                    int s=0;
                    while(!q.empty()) {
                        ++s;
                        int x = q.front(); q.pop();
                        int y = q.front(); q.pop();
                        for(int i=0; i<4; ++i) {
                            int newX = x + dx[i];
                            int newY = y + dy[i];
                            if(newX>=0 && newX<n && newY>=0 && newY<m && grid[newX][newY]) {
                                grid[newX][newY] = 0;
                                q.push(newX);
                                q.push(newY);
                            }
                        }
                    }
                    ans = max(ans, s);
                }
        return ans;

    }
};
