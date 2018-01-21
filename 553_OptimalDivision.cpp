/**
553. Optimal Division ::
Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how
to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should
NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
since they don't influence the operation priority. So you should return "1000/(100/10/2)".

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
**/

/*class Solution {
public:
	string optimalDivision(vector<int> &nums) {
        int n = nums.size();
		if (n == 1)
			return string(to_string(nums[0]));
		if (n == 2)
			return string(to_string(nums[0]) + "/" + to_string(nums[1]));

		string ans(to_string(nums[0]) + "/");
		string tmp(to_string(nums[1]));
		for (int i = 2; i < n; ++i)
			tmp += "/" + to_string(nums[i]);
		return ans += "(" + tmp + ")";
	}
};*/


class Solution {
public:
    typedef pair<double, string> pis;
    static pis div(pis x, pis y)
    {
        if(y.second.find("/") != string::npos) y.second = string("(") + y.second + string(")");
        return pis(x.first / y.first, x.second + "/" + y.second);
    }
    static pis dfs(vector<int>& a, int l, int r, bool domax = true)
    {
        if(l == r)
            return pis(a[l], to_string(a[l]));
        pis ans;
        if(domax) ans.first = -1; else ans.first = 1e40;
        for(int i = l + 1; i <= r; ++i)
        {
            pis c = div(dfs(a, l, i - 1, domax), dfs(a, i, r, !domax));
            if(domax) ans = max(ans, c); else ans = min(ans, c);
        }
        return ans;
    }
    string optimalDivision(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1, true).second;
    }
};
