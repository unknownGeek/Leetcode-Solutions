/**
491. Increasing Subsequences::
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
1) The length of the given array will not exceed 15.
2) The range of integer in the given array is [-100,100].
3) The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
**/
class Solution {
private:
    void dfs(int index, vector<int> &curr, vector<int> const& nums)
    {
        if(curr.size()>1)
            s.insert(curr);
        for(int i=index; i<nums.size(); ++i)
        {
            if(!curr.empty() && curr.back() > nums[i])
                 continue;
            curr.push_back(nums[i]);
            dfs(i+1, curr, nums);
            curr.pop_back();

        }
    }
public:
    set<vector<int>> s;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<2)return res;
        vector<int> curr;
        dfs(0, curr, nums);
        for(vector<int> v : s)
            res.push_back(v);
        return res;
    }
};
