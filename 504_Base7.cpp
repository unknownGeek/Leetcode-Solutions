/**
504. Base 7 ::
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].
**/class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return string("0");
        string ans("");
        bool neg = false;
        if(num < 0)
        {
            neg = true;
            num = -num;
        }
        while(num)
        {
            string tmp(ans);
            ans = "";
            ans += (char) ('0' + (num % 7));
            ans += tmp;
            num /= 7;
        }
        if(neg)
            ans = "-" + ans;
        return ans;
    }
};
