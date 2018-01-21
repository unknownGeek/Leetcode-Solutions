/**
402. Remove K Digits ::
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the
smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
**/



//Version 1 ::
class Solution {
public:
    string removeKdigits(string num, int k) {
       while(k){
            int n = num.size();
            bool found = false;
            for (int i = 0; i < n-1;i++)
                if (num[i]>num[i+1]) {
                    found = true;
                    num.erase(i,1);
                    break;
                }

            if (!found) break;
            k--;
        }

        while(k>0)
            num.erase(num.size()-1,1),k--;
        if(num.empty())
            return "0";
        int s = 0;
        while (s<num.size()-1 && num[s]=='0')
            ++s;
        return num.substr(s);
    }
};


//Version 2 ::
class Solution {
public:
	string removeKdigits(string num, int k) {
		int n = num.length();
		if(n == k)
            return string("0");
		string sol("");
		stack<int> s;
		vector<int> R;
		R.reserve(n);
		for(int i=0; i<n; ++i)
		{
			while(!s.empty() && num[s.top()] > num[i])
			{
				R.push_back(s.top());
				s.pop();
			}
			s.push(i);
		}
		while(!s.empty())
		{
			R.push_back(s.top());
			s.pop();
		}
		for(int i=0; i<k; ++i)
            num[R[i]] = ' ';
		int j = 0;
		for(char ch : num)
            if(ch != ' ')
                sol += ch;
		for(int i=0; i<n-k; ++i)
            if(sol[i] != '0')
                return sol.substr(i);
		return "0";
	}
};
