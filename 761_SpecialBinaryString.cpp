/*
761. Special Binary String ::
Special binary strings are binary strings with the following two properties:

The number of 0's is equal to the number of 1's.
Every prefix of the binary string has at least as many 1's as 0's.
Given a special string S, a move consists of choosing two consecutive, non-empty, special substrings of S, and swapping them. (Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.)

At the end of any number of moves, what is the lexicographically largest resulting string possible?

Example 1:
Input: S = "11011000"
Output: "11100100"
Explanation:
The strings "10" [occuring at S[1]] and "1100" [at S[3]] are swapped.
This is the lexicographically largest string possible after some number of swaps.
Note:

S has length at most 50.
S is guaranteed to be a special binary string as defined above.
*/
class Solution {
public:
  string makeLargestSpecial(string S) {
    if(S.empty()){
        return S;
    }
    int cnt = 0, lastIndex = 0;
    /*
      cnt stores the sum of '1'(as +1) and '0'(as -1), if somewhere at any point cnt becomes Zero, then the current string 
      has equal number of 1's and 0's in it and basically it draws a Mountain Like Shape[Peak Point]
    */
    vector<string> inners;
    int n = S.length();
    for(int i=0; i<n; ++i){
      if (S[i] == '1'){
          ++cnt;
      }
      else{
            --cnt;
           
            if (cnt == 0){//We found a Mountain
                  if(lastIndex==0 && i==n-1){ // complete string is a mountain
                       return string( "1" + makeLargestSpecial(S.substr(1, n-2)) + "0");
                  }else{
                        string inner = makeLargestSpecial(S.substr(lastIndex, i-lastIndex+1));
                        lastIndex = i+1;
                        inners.push_back(inner);
                  }
             }
        }
    }
      
    sort(inners.begin(), inners.end(), greater<string>());//Sorting lexicographically
    string ans("");
    for(string &inner : inners){
        ans += inner;
    }
    return ans;
  }
};