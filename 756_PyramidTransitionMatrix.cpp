/*
756. Pyramid Transition Matrix ::
We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

Return true if we can build the pyramid all the way to the top, otherwise false.

Example 1:
Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  D   E
 / \ / \
X   Y   Z

This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
Example 1:
Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
Note:
bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/

//Version#1 ::
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        set<char> dp[n][n];//Or We Can Write like this->, vector<vector<set<char> > > dp(n, vector<set<char> >(n));

        map<string, vector<char> > mp;
        for (auto s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        for (int i = 0; i < n; i++) {
            dp[0][i].insert(bottom[i]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                for (char A : dp[i - 1][j]) {
                    for (char B : dp[i - 1][j + 1]) {
                        string now = "";
                        now = now + A + B;
                        // cout << "i, j, now = " << i << ", " << j << ", " << now << endl;
                        for (char C : mp[now]) {
                            // cout << "i, j, c = " << i << ", " << j << ", " << c << endl;
                            dp[i][j].insert(C);
                        }
                    }
                }
            }
        }
        return !dp[n - 1][0].empty();
    }
};




//Version#2 ::
class Solution {
private:
        int d[26][26];
        int level[2][111];
        int getBit(int num, int i){
            return (num >> i) & 1;
        }
public: 
        bool pyramidTransition(string bottom, vector<string>& allowed) {
            memset(d, 0, sizeof d);
            memset(level, 0, sizeof level);
            for(string str : allowed){
                d[str[0]-'A'][str[1]-'A'] |= 1<<(str[2]-'A');
            }

            int n=bottom.length();
            for(int i=0; i<n; ++i){
                level[0][i] = 1<<(bottom[i]-'A');
            }

            int curr=0, next=1;
            for(int i=n; i>=2; --i){
                memset(level[next], 0, sizeof level[next]);
                for(int j=0; j<i-1; ++j){
                    for(int k1=0; k1<7; ++k1){
                        for(int k2=0; k2<7; ++k2){
                            if(getBit(level[curr][j], k1) && getBit(level[curr][j+1], k2) ){
                                level[next][j] |= d[k1][k2];
                        }
                     }
                  }
                }
                swap(curr,next);
            }
            return level[curr][0] != 0;
    }
};


//Version#3 ::
class Solution {
private:
    unordered_map<string, vector<char>> next;
    
    bool generate_options(string current, int index, string& row)
    {
        if (index == current.size() - 1) return pyramidTransition(row);
        string pair = current.substr(index, 2);
        for(int i = 0; i < next[pair].size(); i++)
        {
            row += next[pair][i];
            if (index == 0)
            {

                if (generate_options(current, index + 1, row)) return true;

            }
            else
            {
                string new_pair;
                new_pair = row.substr(row.size() - 2, 2);
                if (next.find(new_pair) != next.end() && generate_options(current, index + 1, row)) return true;
            }
            row.pop_back();
        }
        return false;
    }
    
    bool pyramidTransition(string current) {
        if (current.size() == 2 && next.find(current) != next.end()) return true;
        string temp_row;
        return generate_options(current, 0, temp_row);
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if (allowed.size() == 0) return false;
        for(const auto& s : allowed) next[s.substr(0, 2)].push_back(s[2]);
        return pyramidTransition(bottom);
    }
};