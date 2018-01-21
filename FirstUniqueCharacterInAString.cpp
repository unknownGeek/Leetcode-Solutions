/**
387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
**/

//Version 1::
class Solution {
public:
    int firstUniqChar(string s) {
     int freq[26]={0};
        for(char ch : s)
              ++freq[ch - 'a'];
        for(int i=0; i<s.size(); ++i)
            if(freq[s[i]-'a']==1)
                 return i;
         return -1;
    }
};


//version 2::
class Solution
{
public:
	int firstUniqChar(string s)
	{
		unordered_map<char, int> Used;
		for (auto & i : s)
		{
			Used[i]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (Used[s[i]] == 1) return i;
		}
		return -1;
	}
};
