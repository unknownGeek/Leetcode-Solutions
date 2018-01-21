/**
461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
**/
//Version 1 ::
class Solution {
public:
    int hammingDistance(int x, int y) {
     return __builtin_popcount(x^y);
    }
};


//Version 2 ::
public class Solution {
    public int hammingDistance(int x, int y) {
        return one(x ^ y);
    }
    private int one(int x) {
        int ans = 0;
        while (x != 0) {
            x &= x - 1;
            ans++;
        }
        return ans;
    }
}

//Version 3 ::
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> a(x);
        bitset<32> b(y);
        int r = 0;
        for (int i = 0; i < 32; i++) {
            if (a[i] != b[i]) r++;
        }
        return r;
    }
};
