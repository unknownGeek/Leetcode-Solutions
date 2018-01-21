//624. Maximum Distance in Arrays
class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int mi = a[0].front(), mx = a[0].back();
        int ans = 0;
        for (int i = 1; i < a.size(); ++i) {
            ans = max(ans, abs(mx - a[i].front()));
            ans = max(ans, abs(mi - a[i].back()));
            mi = min(mi, a[i].front());
            mx = max(mx, a[i].back());
        }
        return ans;
    }
};
