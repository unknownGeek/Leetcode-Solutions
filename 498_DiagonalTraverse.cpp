/**
498. Diagonal Traverse ::
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]

Note:
The total number of elements of the given matrix will not exceed 10,000
**/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
       if(matrix.empty())return vector<int> {};
        int n = matrix.size();
        int m = matrix[0].size();
        typedef pair<int, int> pii;
        vector<pii> a;
        for(int i=0; i<n; ++i)
             for(int  j=0; j<m; ++j)
                   a.push_back(pii{i, j});
        sort(a.begin(), a.end(), [](pii const& a, pii const& b){
            if(a.first + a.second != b.first + b.second)
                return a.first+a.second < b.first+b.second;
            if((a.first + a.second)&1)
                return a.first < b.first;
            else
                return a.first > b.first;
        });
        vector<int> ans;
        for(pii const& p : a)
            ans.push_back(matrix[p.first][p.second]);
        return ans;
    }
};
