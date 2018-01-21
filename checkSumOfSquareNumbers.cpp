/**
Check Sum of Square Numbers ::
Given a integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Have you met this question in a real interview? Yes
Example
Given n = 5
Return true // 1 * 1 + 2 * 2 = 5

Given n = -5
Return false
**/

/*
//Version 1:: Fine But Gives TLE
class Solution {
public:

     // @param : the given number
     // @return: whether whether there're two integers

    bool checkSumOfSquareNumbers(int c) {
        // write your code here
        if(c<0)return false;
        for(int i=0; i*i<=c; ++i){
            for(int j=0; j*j<=c; ++j){
                if(i*i + j*j == c)return true;
            }
        }
        return false;
    }
};
*/



/*
//Version 2 :: Fine But Gives MLE
class Solution {
public:

    bool checkSumOfSquareNumbers(int c) {
        // write your code here
        if(c<0)return false;
        unordered_map<int, bool> lol;
        for(int i=0; i*i<=c; ++i){
            lol[c-i*i]=true;
        }
        for(int j=0; j*j<=c; ++j){
            if(lol.find(j*j)!=lol.end())return true;
        }



        //Or We Write as follow also :
        //for(int i=0; i*i<=c; ++i){
        //   lol[i*i]=true;
        //    if(lol.find(c - i*i)!=lol.end())return true;
        //}
        return false;
    }
};
*/



//Version 3 :: Perfect
class Solution {
public:

    bool checkSumOfSquareNumbers(int c) {
        // write your code here
        if(c<0)return false;
        int left = 0, right = sqrt(c);
        while(left <= right){
            int curr = left*left + right*right;
            if(curr==c)return true;
            if(curr>c)
                  --right;
            else
                ++left;
        }
        return false;
    }
};
*
