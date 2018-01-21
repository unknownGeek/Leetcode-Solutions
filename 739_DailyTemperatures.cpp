/*
Daily Temperatures :: https://leetcode.com/contest/weekly-contest-61/problems/daily-temperatures/
Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

//Version#1 :: Brute-Force in O(n^2) time
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans;
        int j;
        for(int i=0; i<n-1; ++i){
            for(j=i+1; j<n; ++j){
                if(temperatures[i] < temperatures[j]){
                    break;
                }
            }
            if(j == n){
                ans.push_back(0);
            }else{
                ans.push_back(j-i);
            }
        }
      ans.push_back(0);
      return ans;
    }
};

//Version#2 :: In Better time complexity
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for(int i=0; i<n; ++i){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                ans[s.top()] = (i - s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ans[s.top()] = 0;
            s.pop();
        }
     return ans;
    }
};
