/**
593. Valid Square ::
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
**/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        function<long(vector<int>, vector<int>)> dist;
        dist = [&] (vector<int> const& a, vector<int> const& b){
            return (b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1]);
        };
        vector<int> d;
        d.push_back(dist(p1, p2));
        d.push_back(dist(p1, p3));
        d.push_back(dist(p1, p4));
        d.push_back(dist(p2, p3));
        d.push_back(dist(p2, p4));
        d.push_back(dist(p3, p4));
        sort(d.begin(), d.end());
        return d[0]>0 && d[0]==d[1] && d[0]==d[2] && d[0]==d[3] && 2*d[0]==d[4] && 2*d[0]==d[5];
    }
};


import java.util.Arrays;

public class Solution {
    private int dis(int[] a, int[] b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[] arr = {dis(p1, p2),
                dis(p1, p3), dis(p1, p4), dis(p2, p3), dis(p2, p4), dis(p3, p4)};
        Arrays.sort(arr);
        return arr[0] > 0 && arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[3] && 2 * arr[0] == arr[4] && 2 * arr[0] == arr[5];

    }
}
