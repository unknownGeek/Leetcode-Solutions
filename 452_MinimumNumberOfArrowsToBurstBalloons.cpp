/**
452. Minimum Number of Arrows to Burst Balloons ::
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and
end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of
start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an
arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps
travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11
(bursting the other two balloons).
**/

bool cmp(pair<int, int> const& a, pair<int, int> const& b){
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty())return 0;
        sort(points.begin(), points.end(), cmp);
        int minArrows = 0;
        long lastBoundary = 1ll*points[0].first - 1;
        for(auto point : points){
            if(lastBoundary < point.first){
                ++minArrows;
                lastBoundary = point.second;
            }
        }
        return minArrows;
    }
};
