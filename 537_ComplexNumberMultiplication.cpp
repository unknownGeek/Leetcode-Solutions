/**
537. Complex Number Multiplication ::
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100].
And the output should be also in this form.
**/
/*class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int p = a.find('+');
        cout<<p<<"\n";
        int n = a.length();
        int x1 = stoi(a.substr(0, p));
        int y1 = stoi(a.substr(p+1, n-p-1));
        cout<<x1<<" "<<y1<<"\n";
        p = b.find('+');
        cout<<p<<"\n";
        int m = b.length();
        int x2 = stoi(b.substr(0, p));
        int y2 = stoi(b.substr(p+1, m-p-1));
        cout<<x2<<" "<<y2<<"\n";
        stringstream ss;
        ss<< x1*x2 - y1*y2;
        string s("");
        ss>>s;
        string ans("");
        ans+=s+'+';
        ss.clear();
        ss<< x1*y2 + x2*y1;
        ss>>s;
        ans+=s+'i';
        return ans;
        //return a;
    }
};*/
/*
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int real_a, imag_a, real_b, imag_b;
        sscanf(a.c_str(), "%d+%di", &real_a, &imag_a);
        sscanf(b.c_str(), "%d+%di", &real_b, &imag_b);
        int real = real_a * real_b - imag_a * imag_b;
        int imag = real_a * imag_b + real_b * imag_a;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};*/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int aa, ab, ba, bb;
        sscanf(a.c_str(), "%d+%di", &aa, &ab);
        sscanf(b.c_str(), "%d+%di", &ba, &bb);
        int ca = aa*ba - ab*bb;
        int cb = ab*ba + aa*bb;
        char ans[100];
        sprintf(ans, "%d+%di", ca, cb);
        return string(ans);
    }
};
