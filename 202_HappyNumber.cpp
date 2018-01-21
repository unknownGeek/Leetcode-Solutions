/**
202. Happy Number ::
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum
of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a
cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
**/

/*
//Version 1:: Using Extra Space
class Solution {
public:
    bool isHappy(int n) {
     if(n==1)return true;
        unordered_map<int, int> lol;
        int num = n;
        while(num!=1){
            int sum = 0;
            while(num){
                sum += (num%10) * (num%10);
                num /= 10;
            }
            if(sum == 1)return true;
            if(lol.find(sum)!=lol.end())
                return false;
            lol[num = sum]=1;
        }
        return false;
    }
};*/

/*
// Version 2 :: O(1)space[ No Extra Space]
class Solution {
public:
bool isHappy(int n) {
    function<int(int)>  digitSquareSum;
    digitSquareSum = [&] (int n) -> int {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    };
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    return slow==1;
  }
};*/

/*
// Version 3 :: O(1)space[ No Extra Space]
class Solution {
public:
    bool isHappy(int n) {
    while(n>6){
        int next = 0;
        while(n){next+=(n%10)*(n%10); n/=10;}
        n = next;
    }
    return n==1;
   }
};*/



// Version 4 :: [Using Extra Space]
class Solution {
public:
    bool isHappy(int n) {
        set<int> inLoop;
        int squareSum, remain;
        while ((inLoop.insert(n)).second) {
            squareSum = 0;
            while (n > 0) {
                remain = n%10;
                squareSum += remain*remain;
                n /= 10;
            }
            if (squareSum == 1)
                return true;
            else
                n = squareSum;
        }
        return false;
      }
};
