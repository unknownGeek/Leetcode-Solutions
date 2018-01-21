/**
326. Power of Three ::
for explanation go to https://leetcode.com/problems/power-of-three/discuss/
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
**/


class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
};

class Solution {
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    int const MaxInt32 = 2147483647; // 2^31 - 1
    bool isPowerOfThree(int n) {
        return (n <= 0 || n > Max3PowerInt) ? false : Max3PowerInt % n == 0;
    }
};
