/*
773. Sliding Puzzle ::
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].

*/


/*
//Version#1 ::
class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    using State = vector<vector<int>>;
    queue<State> q;
    q.push(board);
    map<State, int> f;
    State ending{{1, 2, 3}, {4, 5, 0}};
    f[board] = 0;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    while (!q.empty()) {
      auto s = q.front();
      q.pop();
      if (s == ending) {
        return f[s];
      }
      int x, y;
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
          if (s[i][j] == 0) {
            x = i;
            y = j;
          }
        }
      }
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (0 <= xx && xx < 2 && 0 <= yy && yy < 3) {
          auto v = s;
          swap(v[xx][yy], v[x][y]);
          if (!f.count(v)) {
            q.push(v);
            f[v] = f[s] + 1;
          }
        }
      }
    }
    return -1;
  }
};*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> dict;
        string res = "123450";
        queue<string> wait_queue;
        string status;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                status += to_string(board[i][j]);
            }
        }
        wait_queue.push(status);
        dict[status] = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!wait_queue.empty() && dict.find(res) == dict.end()) {
            string cur = wait_queue.front();
            wait_queue.pop();
            int pos = 0;
            for (int i = 0; i < 6; i++) {
                if (cur[i] == '0') {
                    pos = i;
                    break;
                }
            }
            int x = pos / 3, y = pos % 3, step = dict[cur];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx <= 1 && ny >= 0 && ny <= 2) {
                    string temp(cur);
                    swap(temp[pos], temp[nx * 3 + ny]);
                    if (dict.find(temp) == dict.end()) {
                        dict[temp] = step + 1;
                        wait_queue.push(temp);
                    }
                }
            }
        }
        if (dict.find(res) == dict.end()) { return -1; }
        return dict[res];
    }
};
