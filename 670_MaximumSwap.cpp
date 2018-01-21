/**
670. Maximum Swap ::
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 10^8]
**/


//Version 1::
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int len = s.length();
        int max=num;
        for(int i=0; i<len-1; ++i)
             for(int j=i+1; j<len; ++j)
              {
               if(s[i]<s[j])
               {
                   swap(s[i], s[j]);
                   max = std::max(max, stoi(s));
                   swap(s[i], s[j]);
               }
             }
      return max;
    }
};


//Version 2::
class Solution {
public:
    int maximumSwap(int n) {
        vector<int> a;
        for (int m = n; m; m /= 10) a.push_back(m % 10);
        int len = a.size();
        vector<int> p10(10);
        p10[0] = 1;
        for (int i = 1; i < 10; ++i) p10[i] = p10[i - 1] * 10;
        int ret = n;
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int cur = n - p10[i] * a[i] + p10[i] * a[j] - p10[j] * a[j] + p10[j] * a[i];
                ret = max(ret, cur);
            }
        }
        return ret;
    }
};
