/**
628. Maximum Product of Three Numbers ::
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,10^4] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
**/

/*
//Version 1:: O(1) space  AND O(nlgn) time solution
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.empty() && nums.size()<3)return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max<int>(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};
*/


//Version 2:: O(1) space  AND O(n) time solution
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.empty() && nums.size()<3)return 0;
        int max1, max2, max3, min1, min2;
        max1=max2=max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max3 = max2;
                max2 = n;
            } else if (n > max3) {
                max3 = n;
            }

            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }
        return max<int>(max1*max2*max3, max1*min1*min2);
    }
};

