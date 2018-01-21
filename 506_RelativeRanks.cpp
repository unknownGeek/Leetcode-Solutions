/**
506. Relative Ranks ::
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be
awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal"
and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
**/
bool cmp(pair<int, int> const& a, pair<int, int> const& b){
    if(a.first != b.first)return a.first > b.first;
    return a.second < b.second;
}
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if(nums.empty())return {};
        int n = nums.size();
        vector<pair<int, int>> ranks;
        int i=-1;
        for(int num : nums)
            ranks.push_back({num, ++i});
        sort(ranks.begin(), ranks.end(), cmp);

        vector<string> order{"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> ans(n);
         i=0;
        for(auto p : ranks){
            if(++i <4)
                ans[p.second] = order[i-1];
            else
                ans[p.second] = to_string(i);
        }

        return ans;

    }
};
