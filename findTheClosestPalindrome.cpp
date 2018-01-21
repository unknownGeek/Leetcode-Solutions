/**
Find the Closest Palindrome ::
Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
**/

class Solution {
public:
    string nearestPalindromic(string n)
{
    int len = (int)n.length();
    long long N = stoll(n);
    string left = n.substr(0, len / 2);
    if(len & 1) left += n[len / 2];
    string right = left.substr(0, len / 2);
    reverse(right.begin(), right.end());
    long long A = stoll(left + right);

    long long B = stoll(left) + 1;
    left = to_string(B);
    right = left.substr(0, len / 2);
    reverse(right.begin(), right.end());
    B = stoll(left + right);

    long long C = stoll(left) - 2;
    left = to_string(C);
    int cut = 0;
    string miss = "";
    if(left[0] == '0' || left.size() < len / 2)
    {
        cut = 1;
        if(len > 1) miss = "9";
    }
    right = left.substr(0, len / 2 - cut);
    reverse(right.begin(), right.end());
    C = stoll(left + miss + right);

    long long minN = A;
    if(A == N || abs(A - N) > abs(B - N) || (abs(A - N) == abs(B - N) && B < A)) minN = B;
    if(abs(minN - N) > abs(C - N) || (abs(minN - N) == abs(C - N) && C < minN)) minN = C;

    return to_string(minN);
}
};
