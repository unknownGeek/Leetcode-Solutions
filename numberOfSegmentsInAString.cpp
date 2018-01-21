/**
Number of Segments in a String ::
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
**/
class Solution {
public:
    int countSegments(string s) {
        if(s.empty())return 0;
        int cnt = 0;
        stringstream ss(s);
        while(ss>>s)
            ++cnt;
        return cnt;
    }
};
