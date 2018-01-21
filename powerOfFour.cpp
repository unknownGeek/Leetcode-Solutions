/**
Power of Four ::
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
**/

class Solution {
public:
    bool isPowerOfFour(int n) {
        return fmod(log10(n)/log10(4), 1)==0;
    }
};

/**
Idea ::
The basic idea is from power of 2, We can use "n&(n-1) == 0" to determine if n is power of 2. For power of 4, the
additional restriction is that in binary form, the only "1" should always located at the odd position.
For example, 4^0 = 1, 4^1 = 100, 4^2 = 10000. So we can use "num & 0x55555555==num" to check if "1" is located at
the odd position.

**/
public class Solution {
    public boolean isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
}

bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}
