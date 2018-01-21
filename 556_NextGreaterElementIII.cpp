/**
556. Next Greater Element III ::
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits
existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
**/


/*

class Solution {
public:
    int nextGreaterElement(int n) {
        string s(to_string(n));
        sort(s.begin(), s.end());
        long ans = 1e14;
        do {
            long x = stoll(s);
            if (n < x && x < ans)
                ans = x;
        } while (next_permutation(s.begin(), s.end()));
        return ans > INT_MAX?-1:ans;
    }
};*/


class Solution {
public:
    int nextGreaterElement(int n) {
        typedef long long ll;
        string s(to_string(n));
        if(!next_permutation(s.begin(), s.end()))
            return -1;
        ll ans;

        sscanf(s.c_str(), "%lld", &ans);//Or we can use, ans = stoll(s);
        if(ans >= (1ll<<31))
            return -1;
        return ans;
    }
};
