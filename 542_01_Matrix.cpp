/**
542. 01 Matrix ::
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
**/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty())return matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sol(n, vector<int>(m));
        typedef pair<int, int> pii;
        #define inf INT_MAX
        queue<pii> q;
        for(int x=0; x<n; ++x)
            for(int y=0; y<m; ++y)
                if(!matrix[x][y])
                {
                    sol[x][y] = 0;
                    q.push(pii(x, y));
                }
                else
                    sol[x][y] = inf;
        const int dx[] = {1, -1, 0,  0};
        const int dy[] = {0,  0, 1, -1};
        while(!q.empty())
        {
            pii curr = q.front(); q.pop();
            int x = curr.first, y = curr.second;
            for(int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && sol[newX][newY] == inf)
                {
                    sol[newX][newY] = sol[x][y] + 1;
                    q.push(pii(newX, newY));
                }
            }
        }
        return sol;
    }
};
