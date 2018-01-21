/*
639. Decode Ways II ::
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.

*/
class Solution {
private:
const int mod = 1e9 + 7;
void checkAndUpdate(int &x, int y)
    {
        x+=y;
    if( x >= mod )
          x -= mod;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0]=1;

        for(int i=0; i<n; ++i)
        {
            //Checking for Singles
            for(int j=1; j<=9; ++j)
                if(s[i] == '*' || s[i] == j+'0')
                      checkAndUpdate(dp[i+1], dp[i]);

            //Checking for Doubles
            if(i == n-1)
                  continue;
            for(int j=1; j<=2; ++j)
            {
                for(int k=0; k<=9; ++k)
                {
                    if(j*10 + k > 26)
                          continue;
                   if(s[i] == '*' || s[i] == j+'0')
                      if((s[i+1]=='*' && k!=0) || s[i+1] == k + '0')
                           checkAndUpdate(dp[i+2], dp[i]);
             }
          }
        }
        return dp[n];
    }
};

