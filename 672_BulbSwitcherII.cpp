/**

672. Bulb Switcher II ::
There is a room with n lights which are turned on initially and 4 buttons on the wall. After performing exactly m unknown operations towards buttons, you need to return how many different kinds of status of the n lights could be.

Suppose n lights are labeled as number [1, 2, 3 ..., n], function of these 4 buttons are given below:

Flip all the lights.
Flip lights with even numbers.
Flip lights with odd numbers.
Flip lights with (3k + 1) numbers, k = 0, 1, 2, ...
Example 1:
Input: n = 1, m = 1.
Output: 2
Explanation: Status can be: [on], [off]
Example 2:
Input: n = 2, m = 1.
Output: 3
Explanation: Status can be: [on, off], [off, on], [off, off]
Example 3:
Input: n = 3, m = 1.
Output: 4
Explanation: Status can be: [off, on, off], [on, off, on], [off, off, off], [off, on, on].
Note: n and m both fit in range [0, 1000].
**/

class Solution {
    public:
    int flipLights(int n, int m) {
        const int B = min(6, n);
        const int T = (1 << B);
        bool *dp = new bool[T];
        for (int i=0; i<T; ++i)
            dp[i]=false;
        dp[0] = true;
        for (int i = 0; i < m; ++i) {
            bool *next = new bool[T];
             for (int i=0; i<T; ++i)
                     next[i] = false;
            for (int j = 0; j < T; ++j) {
                if (dp[j]) {
                    next[op1(j, B)] = true;
                    next[op2(j, B)] = true;
                    next[op3(j, B)] = true;
                    next[op4(j, B)] = true;
                }
            }
            dp = next;
        }

        int cnt = 0;
        for (int i=0; i<T; ++i)
            if (dp[i])
                ++cnt;

        return cnt;
    }

    private:
    int flip(int num, int bit) {
        return num ^ (1 << bit);
    }

    int op1(int num, int B) {
        for (int i = 0; i < B; ++i) {
            num = flip(num, i);
        }
        return num;
    }

    int op2(int num, int B) {
        for (int i = 1; i < B; i += 2) {
            num = flip(num, i);
        }
        return num;
    }

    int op3(int num, int B) {
        for (int i = 0; i < B; i += 2) {
            num = flip(num, i);
        }
        return num;
    }

    int op4(int num, int B) {
        for (int i = 0; i < B; i += 3) {
            num = flip(num, i);
        }
        return num;
    }
};
