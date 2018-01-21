/**
Target Sum ::
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
**/

//dfs only
class Solution {
private:
    void calc(int index, int sum, int const& target, vector<int>& nums)
    {
        if(index==nums.size())
        {
            if(sum == target)
                      ++cnt;
        }
      else
      {
          calc(index+1, sum+nums[index], target, nums);
          calc(index+1, sum-nums[index], target, nums);
      }
    }
public:
    int cnt;
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty())return 0;
        cnt=0;
        calc(0, 0, target, nums);
        return cnt;
    }
};


/**
//dfs + memoization
class Solution {
private:
    int calc(int index, int sum, int const& target, vector<int>& nums, int (*dp)[2005])
    {
        if(index==nums.size())
        {
            if(sum == target)
                      return 1;
            else
                return 0;
        }
         if(dp[index][sum+1000]!=INT_MIN)return dp[index][sum+1000];
         int countWhenAdding =  calc(index+1, sum+nums[index], target, nums, dp);
         int countWhenSubtracting = calc(index+1, sum-nums[index], target, nums, dp);
        return dp[index][sum+1000]=countWhenSubtracting+countWhenAdding;

    }
public:
    int cnt;
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty())return 0;
        int n=nums.size();
        int dp[n][2005];
        for(int i=0; i<n; ++i)
            for(int j=0; j<2005; ++j)
                 dp[i][j]=INT_MIN;
        return calc(0, 0, target, nums, dp);
       }
};**/
