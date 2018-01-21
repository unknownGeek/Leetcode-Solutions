/**
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.

Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
**/

/*
477. Total Hamming Distance ::
//Version 1 :: Correct but gives TLE
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.empty())return 0;
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-1; ++i)
            for(int j=i+1; j<n; ++j)
                 cnt += __builtin_popcount(nums[i]^nums[j]);
        return cnt;
    }
};
*/
//Version 2 ::
class Solution {
    public:
    int totalHammingDistance(vector<int> &nums) {
        if(nums.empty())return 0;
        int n = nums.size();
        int bitsOfOne[32]={0};
        int total = 0;
        for(int i = 0; i < 32; i++) {
            for(int num : nums)
                bitsOfOne[i] += (num>>i)&1;
            total += (n - bitsOfOne[i]) * bitsOfOne[i];
        }
        return total;
    }
};
