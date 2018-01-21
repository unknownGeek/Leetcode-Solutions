/**
526. Beautiful Arrangement ::
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers
successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation:

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
**/


//Version 1::
class Solution {
public:
    int countArrangement(int n) {
        const int MAXN = 15;
        int d[1<<MAXN];
        memset(d, 0, sizeof(d));
        d[0] = 1;
        for (int mask = 1; mask < 1<<n; mask++){
            int c = __builtin_popcount(mask);
            for (int j = 0; j < n; j++)
                if (mask>>j&1)
                    if (c % (j+1) == 0 || (j+1) % c == 0)
                        d[mask] += d[mask^1<<j];
        }
        return d[(1<<n)-1];
    }
};





//Version 2:
class Solution {
public:
    int countArrangement(int N) {
        int cnt = 0;
        bool visited[N+1];
        memset(visited, false, sizeof visited);
        function<void(int)> dfs;
        dfs = [&] (int pos){
             if (pos > N) {
            ++cnt;
            return;
        }
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                dfs(pos + 1);
                visited[i]=false;
            }
         }
        };
        dfs(1);
        return cnt;
    }
};


//Version 3::
class Solution {
public:
    int countArrangement(int N) {
        nums.resize(N + 100);
        visited = vector<char>(N + 100, 0);
        ans = 0;
        dfs(0, N);
        return ans;
    }
private:
    void dfs(int cur, int n) {
        if (cur == n) {
            ans++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }
            if (i % (cur + 1) == 0 || (cur + 1) % i == 0) {
                nums[cur] = i;
                visited[i] = 1;
                dfs(cur + 1, n);

                visited[i] = 0;
            }
        }
    }
private:
    int ans;
    vector<int> nums;
    vector<char> visited;
};
