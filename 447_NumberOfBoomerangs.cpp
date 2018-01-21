/**
447. Number of Boomerangs ::
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance
 between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range
[-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
**/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for(const auto& p : points) {
            unordered_map<int,int> lol;
            for(const auto& pp : points) {
                int x = pp.first - p.first;
                int y = pp.second- p.second;
                ++lol[x*x+y*y];
            }
            for(const auto& p : lol) {
                int cnt = p.second;
                ans += cnt*(cnt-1);
            }
        }
        return ans;
    }
};
