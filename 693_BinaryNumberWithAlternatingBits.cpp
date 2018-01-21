/**
693. Binary Number with Alternating Bits ::
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
**/
class Solution {
public:
    bool hasAlternatingBits(int num) {
        int last = num%2;
        num >>= 1;
        while(num){
            int curr = num%2;
            if(last == curr)return false;
            num >>= 1;
            last = curr;
        }
      return true;
    }
};



class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long x = n;
        if(x&1)
            x<<=1;
        while(x) {
            if(x%4!=2) return false;
            x>>=2;
        }
        return true;
    }
};



class Solution {
public:
    bool hasAlternatingBits(int n) {
        long i=1;
        while(i<n) {
            if(i&1)
                i<<=1;
            else
                i=(i<<1)+1;
        }
        return i==n;
    }
};


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int expected = n&1;
        while(n) {
            if (expected != (n&1))
                return false;
            n>>=1;
            expected=1-expected;
        }
        return true;
    }
};
