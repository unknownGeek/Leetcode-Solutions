/**
409. Longest Palindrome ::
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built
with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
**/

class Solution {
public:
    int longestPalindrome(string s) {
    	int freq[1<<8]={0};
    	for(char ch : s)
            ++freq[int(ch)];
    	int sum = 0;
        bool oops = false;
    	for(int f : freq)
    	{
    		sum += f - (f&1);
    		if(f&1)
                oops = true;
    	}
    	return sum + oops;
    }
};
