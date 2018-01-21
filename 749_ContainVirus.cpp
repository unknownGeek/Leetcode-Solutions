/*
749. Contain Virus ::
A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

Example 1:
Input: grid = 
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
Example 2:
Input: grid = 
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
Example 3:
Input: grid = 
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.
Note:
The number of rows and columns of grid will each be in the range [1, 50].
Each grid[i][j] will be either 0 or 1.
Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.*/


class Solution {
public:
    int a[55][55];
    int visit[55][55];
    int n, m;
    
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    //const int d_op[4] = {2, 3, 0, 1};//No Need
    
    bool hasWall[55][55][4];
    
    // Returns the number of threatened cells
    int dfs(int x, int y, int visitId) {
        if (visit[x][y] == visitId) {
            return 0;
        }
        if (!a[x][y]) {
            return visit[x][y] = visitId, 1;
        }
        visit[x][y] = visitId;
        int ret = 0;
        for (int id = 0; id < 4; id++) {
            if (hasWall[x][y][id]) continue;
            int x1 = x + dx[id];
            int y1 = y + dy[id];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
                ret += dfs(x1, y1, visitId);
            }
        }
        return ret;
    }
    
    
    int addWalls(int visitId) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visit[i][j] == visitId && a[i][j]) {
                    for (int id = 0; id < 4; id++) {
                        if (hasWall[i][j][id]) continue;
                        int x = i + dx[id];
                        int y = j + dy[id];
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            if (a[x][y] == 0) {
                                hasWall[i][j][id] = 1;
                                //hasWall[x][y][d_op[id]] = 1;//No Need
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    void spread() {
        int affected[55][55];
        memset(affected, 0, sizeof(affected));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    for (int id = 0; id < 4; id++) {
                        if (hasWall[i][j][id]) continue;
                        int x = i + dx[id];
                        int y = j + dy[id];
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            if (a[x][y] == 0) {
                                affected[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] |= affected[i][j];
            }
        }
    }
    
    int containVirus(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = grid[i][j];
            }
        }
        int ans = 0;
        memset(hasWall, 0, sizeof(hasWall));
        while (1) {
            memset(visit, 0, sizeof(visit));
            int maxCnt = -1;
            int x0 = 0, y0 = 0;
            int visitId = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!visit[i][j] && a[i][j]) {
                        // Found a new region
                        int cnt = dfs(i, j, ++visitId);
                        if (cnt > maxCnt) {
                            maxCnt = cnt;
                            x0 = i, y0 = j;
                        }
                    }
                }
            }
            if (maxCnt <= 0) {
                break;
            }
            ans += addWalls(visit[x0][y0]);
            spread();
        }
        return ans;
    }
};