//625. Minimum Factorization
/*
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:
48
Output:
68

Example 2
Input:
15
Output:
35
*/
class Solution {
public:
    int smallestFactorization(int a) {

        if (a==1) return 1;

        vector<int> ans;
        for(int i=9;i>=2;i--) {
            while(a%i==0) {
                a/=i;
                ans.push_back(i);
            }
        }
        if(a>1) return 0;
        long long ret = 0;
        for(int i=(int)ans.size()-1;i>=0;i--) {
            ret = ret * 10 + ans[i];
            if (ret >= (1LL<<31))
                return 0;
        }
        return (int)ret;
    }
};
