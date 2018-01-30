/*
774. Minimize Max Distance to Gas Station ::
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.

*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second  
#define pb push_back
#define mp make_pair
#define pi acos(-1.0) /* pi=3.14159... */
#define nline printf("\n")
#define mem(arr,b) memset(arr,b,sizeof(arr))/*here  b=0 or b=-1 only & arr=array*/
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr) /* For FAST I/O */
 
//debugging snippets
#define debug(x)        cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<"\n";
#define debug2(x, y)     cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<"\n";
#define debug3(x, y, z)  cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<"\n";
#define debug4(x, y, z ,w)  cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<" | "#w" ="<<w<<"\n";
 
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define SORT(v) sort(ALL(v))
#define ALL(X) (X).begin(), (X).end()
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))


/*
//Version#1 ::
class Solution {
    bool check(vector<int>& sta, int k, double dist) {
        int cnt = 0;
        double pre = sta[0];
        int next = 1;
        while (next < sta.size()) {
            if (pre + dist < sta[next]) {
                ++cnt;
                pre += dist;
                if (cnt > k) return false;
            } else {
                pre = sta[next++];
            }
        }
        return true;
    }
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        sort(stations.begin(), stations.end());
        double l = 0.0, r = 1e8;
        while (r - l > 1e-7) {
            double mid = (l + r) / 2;
            if (check(stations, K, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
};*/


/*
//Version#2 ::
class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int K) {
    if (stations.size() <= 1) {
      return 0;
    }
    double s = 0, e = 1e9;
    auto ck = [&](double x) {
      long long used = 0;
      for (int i = 1; i < stations.size(); ++i) {
        auto dis = stations[i] - stations[i - 1];
        used += (int)ceil(dis / x) - 1;
      }
      return used <= K;
    };
    while (e - s > 1e-9) {
      double mid = 0.5 * (s + e);
      if (ck(mid)) {
        e = mid;
      } else {
        s = mid;
      }
    }
    return e;
  }
};*/
    
    
/*
//Version#3::
class Solution {
public:
    int N, M;
    vector<int> sts;
    
    bool ok(double dis)
    {
        int cnt = 0;
        for (int i = 0; i < N - 1 && cnt <= M; ++i)
            cnt += (sts[i + 1] - sts[i]) / dis;
        return cnt <= M;
    }

    double minmaxGasDist(vector<int>& stations, int K) {
        sts = stations;
        N = sts.size();
        M = K;
        double lo = 0.00000001, hi = 10e9;
        while (hi - lo > 0.00000001)
        {
            double mid = (hi + lo) / 2;
            if (ok(mid))
                hi = mid;
            else
                lo = mid;
        }
        return lo;
    }
};*/

//Version#4::
class Solution {
public:
    double minmaxGasDist(vector<int> stations, int K) {
        double l = 0.0;
        double r = 1e8;

        while (r - l > 0.000000001) {
            double m = l + (r - l) / 2;
            int needs = 0;
            for (int i = 0; i < stations.size() - 1; i++) {
                int d = stations[i+1] - stations[i];
                needs += (int) (d / m);
            }
            if (needs > K) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};
