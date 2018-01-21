/*604. Desing Compressed String Iterator::
https://leetcode.com/articles/desing-compressed-string-iterator/
*/
class StringIterator {
public:
    vector<pair<char,int> > a;
    int x,y;
    StringIterator(string s) {
      a.clear();
      char c,i;
      int now;
      now=0;
      for (i=0;i<s.length();i++)
      {
        if ((s[i]>='0')&&(s[i]<='9'))
        {
          now*=10;
          now+=s[i]-'0';
        }
        else
        {
          if (now>0)
          {
            a.push_back(make_pair(c,now));
          }
          c=s[i];
          now=0;
        }
      }
      if (now>0)
        a.push_back(make_pair(c,now));
      x=0;y=0;
    }

    char next() {
      if (x>=a.size()) return ' ';
      else
      {
        char c;
        c=a[x].first;
        y++;
        if (y==a[x].second)
        {
          x++;y=0;
        }
        return c;
      }
    }

    bool hasNext() {
      return x<a.size();
    }
};
