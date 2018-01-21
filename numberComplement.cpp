/**
Number Complement ::
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary
representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
**/

//Version 1 ::
class Solution {
public:
    int findComplement(int num) {
        bitset<32> b(~num);
        //cout<<b<<"\n";
        int i;
        for(i=31; i>=0; --i)
        {
          //  cout<<b[i];
            if(b[i]==0)
                break;
        }
        if(i<0)return 1;
        //cout<<"\n"<<i<<"\n";
        int ans = 0;
        while(--i>=0){
          //  cout<<i<<" ";
            ans += b[i]*(1ll<<i);
        }
        return ans;
    }
};

//Version 2 ::
class Solution {
public:
   int findComplement(int num) {
    int res = 0;
    bool isSet = false;
    for (int i = 31; i >= 0; i--) {
        if(!isSet){
            if((1 << i) & num)
                 isSet = true;
        }
        else{
            if((1 << i) & num)
                continue;
            else
                res |= (1 << i);
        }
    }
    return res;
}
};
