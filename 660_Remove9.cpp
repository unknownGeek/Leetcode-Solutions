/**
660. Remove 9::
Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...

So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...

Given a positive integer n, you need to return the n-th integer after removing. Note that 1 will be the first integer.

Example 1:
Input: 9
Output: 10
Hint: n will not exceed 9 x 10^8.
**/

/**
//Version 1 :: Brute Force, Will Give TLE
class Solution {
private:
    bool containsNine(string str)
    {
        for(char ch : str)
            if(ch=='9')
                return true;
        return false;
    }
public:
    int newInteger(int n) {
        if(n<9)return n;
        int cnt=8;
        for(int num = 9; num<=9e8; ++num)
        {
            if(containsNine(to_string(num)))
                continue;
            ++cnt;
            if(cnt==n)
                return num;
        }
        return -1;

    }
};*/

/**
//Version 2 :: Perfect
class Solution {
public:
    int newInteger(int n) {
        if(n<9)return n;
        string str("");
        while(n){
            str+=(static_cast<char>(n%9) + '0');
            n/=9;
        }
        stringstream ss;
        reverse(str.begin(), str.end());
        ss<<str;
        int num;
        ss>>num;
        return num;


    }
};
**/


//Version 3 :: Perfect and Same as Version 2
class Solution {
public:
    int newInteger(int n) {
        if(n<9)return n;
        vector<int> arr;
        while(n){
           arr.push_back(n%9);
            n/=9;
        }
        int num = 0;

        for(int i=arr.size()-1; i>=0; --i)
            num = 10*num + arr[i];
        return num;


    }
};
