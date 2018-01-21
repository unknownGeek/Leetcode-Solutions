/**
532. K-diff Pairs in an Array ::
Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here
a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute
difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].
**/


//Version 1::
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int> lol;
        set<int> s;
        for (int num : nums) {
            if (lol.count(num - k)) {
                s.insert(num);
            }
            ++lol[num];
        }
        return s.size();
    }
};


//Version 2::
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        map<int, int> cnt;
        for(auto x: nums) ++cnt[x];
        map<int, int> cnt2 = cnt;
        int ans = 0;
        if(k == 0)
        {
            for(auto pair: cnt)
                ans += (pair.second > 1);
        }
        else
        {
            for(auto pair: cnt)
                ans += (cnt2[pair.first + k] > 0);
        }
        return ans;
    }
};


//Version 3::
class Solution {
public:
    int findPairs(vector<int>& nums, int K) {
        if (K < 0) return 0;
        int n = nums.size();
        unordered_map<int, int> M;
        for (auto x:nums) M[x]++;
        int ans = 0;
        for (auto t:M) {
            int x = t.first;
            int y = x + K;
            if (y == x) {
                if (M[x] > 1) ans ++;
            }
            else {
                if (M.find(y) != M.end()) ans++;
            }
        }
        return ans;
    }
};

//Version 4::
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - nums[i] == k) { res++; break; }
                else if (nums[j] - nums[i] > k) break;
            }
        }
        return res;
    }
};



//Version 5::
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        map<int, int> s;
        for (int n : nums) {
            s[n]++;
        }
        int ans = 0;
        for (auto& pr : s) {
            int n = pr.first;
            if (k == 0 && pr.second > 1 || k != 0 && s.count(n + k)) {
                ans++;
            }
        }
        return ans;
    }
};
