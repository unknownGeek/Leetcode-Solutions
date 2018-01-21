/**
390. Elimination Game ::
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
**/

//Version 1 :: Runs Fine But Gives MLE [Memory Limit Exceeded] when n > 1000000
class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return 1;
        vector<int> nums;
        for(int i=2; i<=n; i+=2)
              nums.push_back(i);
        bool left = true;
        vector<int> aux(nums);
        while(aux.size()!=1){
            aux.swap(nums);
            if(left){
                aux.clear();
                for(int i=nums.size()-2; i>=0; i-=2)
                    aux.push_back(nums[i]);
                reverse(aux.begin(), aux.end());
            }
            else{
                 aux.clear();
                for(int i=1; i<nums.size(); i+=2)
                    aux.push_back(nums[i]);
            }
            left = !left;
        }
         return aux[0];
    }
};

//Version 2 :: Perfect Solution
class Solution {
public:
    int lastRemaining(int n) {

        stack<bool> st;
        while (n > 1) {
            // always view as 1,2,3
            // Remove from left
            n >>= 1;
            st.push(true);
            if (n == 1) break;

            // Remove the right
            n&1 ? st.push(true) : st.push(false);
            n >>= 1;
        }
        int res = 1;
        while (!st.empty()){
            res = st.top() ? res<<1 : ((res<<1) - 1);
            st.pop();
        }
        return res;
    }
};
