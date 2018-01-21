/**
507. Perfect Number ::
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
**/

//Version 1::
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=0)return 0;
        int ret=0;
        for(int i=1;i*i<=num;i++){
            if(num%i==0){
                ret+=i;
                if(i!=num/i)ret+=num/i;
            }
        }
        return ret==2*num;
    }
};

/*
//Version 2::
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) return false;
        long sum = 0;
        for (long i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                long cb = i;
                long wb = num / i;
                if (cb < num) sum += cb; // cb < num just to take care when num = 1
                if (wb != cb && wb < num) sum += wb;
            }
        }
        return num == sum;
    }
};*/
