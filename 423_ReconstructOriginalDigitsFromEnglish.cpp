/**
423. Reconstruct Original Digits from English ::
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or
"zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
**/
class Solution {
public:
    string originalDigits(string s) {
        string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        int freq[1<<8] = {0}, digits[10] = {0};
        for (char ch : s)
            ++freq[ch];
        digits[0] = freq['z'];
        for (char ch : words[0])
            freq[ch] -= digits[0];

        digits[2] = freq['w'];
        for (char ch : words[2])
            freq[ch] -= digits[2];

        digits[4] = freq['u'];
        for (char ch : words[4])
            freq[ch] -= digits[4];

        digits[6] = freq['x'];
        for (char ch : words[6])
            freq[ch] -= digits[6];

        digits[8] = freq['g'];
        for (char ch : words[8])
            freq[ch] -= digits[8];

        digits[1] = freq['o'];
        for (char ch : words[1])
            freq[ch] -= digits[1];

        digits[3] = freq['h'];
        for (char ch : words[3])
            freq[ch] -= digits[3];

        digits[5] = freq['f'];
        for (char ch : words[5])
            freq[ch] -= digits[5];

        digits[7] = freq['s'];
        for (char ch : words[7])
            freq[ch] -= digits[7];

        digits[9] = freq['i'];
        for (char ch : words[9])
            freq[ch] -= digits[9];

        string ret("");
        for (int i = 0; i < 10; i++) {
            if (digits[i] == 0)
                continue;
            char ch = '0' + i;
            string str(digits[i], ch);
            ret += str;
        }
        return ret;
    }
};
