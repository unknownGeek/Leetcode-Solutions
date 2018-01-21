/**
592. Fraction Addition and Subtraction ::
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation
result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2,
you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive,
then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in
the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
**/


/*class Solution {
public:
  string fractionAddition(string s) {
    long p = 0, q = 1, p1, q1, t;
    for (size_t i = 0, j; i < s.size(); i = j) {
      j = s.find_first_of("+-", i+1);
      if (j == string::npos) j = s.size();
      auto k = s.find('/', i);
      long x = stol(s.substr(i, k-i)), y = stol(s.substr(k+1, j));
      p1 = p*y+q*x;
      q1 = q*y;
      t = __gcd(p1, q1);
      p = p1/t;
      q = q1/t;
      if (q < 0) p *= -1, q *= -1;
    }
    return to_string(p)+"/"+to_string(q);
  }
};*/



#define _int64 long long

char tmp[100];

_int64 gcd(_int64 x,_int64 y)
{
  if (y==0) return x;
  else return gcd(y,x%y);
}
_int64 lcm(_int64 x,_int64 y)
{
  return x/gcd(x,y)*y;
}


void doit(_int64& y1,_int64& y2,_int64 x1,_int64 x2)
{
  _int64 z1,z2,tmp;
  //cout<<y1<<" "<<y2<<" "<<x1<<" "<<x2<<endl;
  z2=lcm(y2,x2);
  z1=y1*(z2/y2)+x1*(z2/x2);
  //cout<<z1<<" "<<z2<<endl;

  tmp=gcd(z1,z2);
  if (tmp<0) tmp=-tmp;
  y1=z1/tmp;y2=z2/tmp;
  //cout<<y1<<" "<<y2<<endl;
}

class Solution {
public:
    string fractionAddition(string s) {
      _int64 x1,x2,now1,now2,p,i;
      char op;
      string s1;
      if (s[0]!='-') s="+"+s;
      now1=0;now2=1;
      while (s!="")
      {
        op=s[0];
        s=s.substr(1);
        for (i=0;i<s.length();i++)
          if ((s[i]=='-')||(s[i]=='+')) break;
        s1=s.substr(0,i);
        s=s.substr(i);
        p=s1.find_first_of('/');
        x1=atoi(s1.substr(0,p).c_str());
        x2=atoi(s1.substr(p+1).c_str());
        if (op=='-') x1=-x1;
        doit(now1,now2,x1,x2);
      }
      sprintf(tmp,"%lld/%lld",now1,now2);
      return tmp;
    }
};
