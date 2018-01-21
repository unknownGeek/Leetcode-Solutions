/**
463. Island Perimeter ::
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are
connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one
island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the
water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100.
Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 stripes around 1's:
**/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        const int dx[] = {1, -1, 0,  0};
        const int dy[] = {0,  0, 1, -1};
        for(int x=0; x<n; ++x){
            for(int y=0; y<m; ++y){
                if(!grid[x][y])continue;
                for(int i=0; i<4; ++i){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if(newX>=0 && newX<n && newY>=0 && newY<m && !grid[newX][newY])
                        ++cnt;
                    if(newX==-1 || newX==n || newY==-1 || newY==m)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};
