/**
K-th Smallest in Lexicographical Order ::
Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 109.

Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

Solution ::
For better explanation, go to
https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/discuss/

**/
class Solution {
//use long in case of overflow
private:
    int calculateSteps(int n, long n1, long n2) {
    int steps = 0;
    while (n1 <= n) {
        steps += min(long(n + 1), n2) - n1;
        n1 *= 10;
        n2 *= 10;
    }
    return steps;
}
public:
    int findKthNumber(int n, int k) {
    int curr = 1;
    --k;
    while (k) {
        int steps = calculateSteps(n, curr, curr + 1);
        if (steps <= k) {
            ++curr;
            k -= steps;
        }
        else {
            curr *= 10;
            --k;
        }
    }
    return curr;
}
};
