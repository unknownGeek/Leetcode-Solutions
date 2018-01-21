/**
231. Power of Two ::
Given an integer, write a function to determine if it is a power of two.
**/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n<=0 ? false : !(n&(n-1));
    }
};




class Solution {
public:
    bool isPowerOfTwo(int n) {
        return fmod(log10(n)/log10(2), 1)==0;
    }
};
