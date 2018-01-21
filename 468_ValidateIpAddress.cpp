/**
468. Validate IP Address ::
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging
from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are
separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could
omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so
2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to
pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334
is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
**/


class Solution {
public:
    bool isFour(string S) {
        int val = 0;
        int count = 0;
        for(int i = 0; i <= S.size(); i++) {
            if(i == S.size() or S[i] == '.') {
                if(i == 0 or S[i - 1] == '.')
                    return false;
                if(!(val >= 0 and val <= 255))
                    return false;
                val = 0;
                count++;
                continue;
            }
            if(S[i] == '0' and i + 1 != S.size() and S[i + 1] != '.')
                return false;
            if(!(S[i] <= '9' and S[i] >= '0'))
                return false;
            val *= 10;
            val += S[i] - '0';
            if(val > 255)
                return false;
        }
        return count == 4;
    }
    bool isSix(string S) {
        int count = 0;
        int terms = 0;
        for(int i = 0; i <= S.size(); i++) {
            if(i == S.size() or S[i] == ':') {
                if(i == 0 or S[i - 1] == ':')
                    return false;
                if(terms == 0 or terms > 4)
                    return false;
                terms = 0;
                count++;
                continue;
            }
            if(!(S[i] <= '9' and S[i] >= '0') and !(S[i] <= 'F' and S[i] >= 'A') and !(S[i] <= 'f' and S[i] >= 'a'))
                return false;
            terms++;
        }
        return count == 8;

    }
    string validIPAddress(string IP) {
        if(isFour(IP))
            return "IPv4";
        if(isSix(IP))
            return "IPv6";
        return "Neither";
    }
};
