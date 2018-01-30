/*
771. Jewels and Stones ::
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second  
#define pb push_back
#define mp make_pair
#define pi acos(-1.0) /* pi=3.14159... */
#define nline printf("\n")
#define mem(arr,b) memset(arr,b,sizeof(arr))/*here  b=0 or b=-1 only & arr=array*/
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr) /* For FAST I/O */
 
//debugging snippets
#define debug(x)        cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<"\n";
#define debug2(x, y)     cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<"\n";
#define debug3(x, y, z)  cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<"\n";
#define debug4(x, y, z ,w)  cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" ="<<z<<" | "#w" ="<<w<<"\n";
 
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
#define SORT(v) sort(ALL(v))
#define ALL(X) (X).begin(), (X).end()
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))


/*
//Version#1 ::
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        unordered_map<char, int> freq;
        for(char & ch : S){
            ++freq[ch];
        }
        int ans = 0;
        for(char & ch : J){
            ans += freq[ch];
        }
        return ans;
    }
};*/


/*
Version#2 ::
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> s(J.begin(), J.end());
      int ans = 0;
      for (char c : S) {
        if (s.count(c)) {
          ++ans;
        }
      }
      return ans;
    }
};*/


/*
//Version#3::
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewls;
        for (const auto& iter : J) {
            jewls.insert(iter);
        }
        int ans = 0;
        for (const auto& iter : S) {
            if (jewls.find(iter) != jewls.end()) {
                ans++;
            }
        }
        return ans;
    }
};*/




//Version#4::
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans=0;
        for(char &j : J){
            for(char &s : S){
                ans += s==j;
            }
        }
        return ans;
    }
};
