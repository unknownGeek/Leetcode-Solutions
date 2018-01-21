/**
551. Student Attendance Record I ::
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two
continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
**/

class Solution {
public:
    bool checkRecord(string s) {
        if(s.empty())return false;
        map<char, int> lol;
        for(char ch : s){
            ++lol[ch];
            if(lol['A']>1)return false;
        }
        int n = s.size();
        function<bool(string)> check;
        check = [&] (string str){
            for(int i=0; i<n-2; ++i)
                if(s.substr(i, 3)=="LLL")
                    return true;
            return false;
        };
        if(lol['L']>2 && check(s))return false;
        return true;

    }
};



class Solution {
public:
  bool checkRecord(string s) {
    int cntA = count(s.begin(), s.end(), 'A');
    bool flag = false;
    for (int i = 2; i < s.size(); ++i) {
      if (s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') {
				flag = true;
      }
    }
		if (!flag && cntA <= 1) {
			return true;
		}
		return false;
  }
};


class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'A') cnt++;
        if (cnt > 1) return false;
        cnt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'L') cnt++;
            else cnt = 0;
            if (cnt > 2) return false;
        }
        return true;
    }
};
