/**
566. Reshape the Matrix ::
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number
and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they
were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the
original matrix.

Example 1:
Input:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous
list.
Example 2:
Input:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
**/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        if(n*m != r*c)return nums;
        vector<vector<int>> mat(r);
        int i=0;
        for(vector<int> row : nums){
            for(int num : row){
                if(mat[i].size()<c)
                    mat[i].push_back(num);
                else
                    mat[++i].push_back(num);
            }
        }
        return mat;
    }
};


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {
        int n = a.size();
        if (n == 0) return a;
        int m = a[0].size();
        if (m == 0) return a;
        if (n * m != r * c) return a;
        vector<vector<int>> ret(r, vector<int>(c));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int pos = i * m + j;
                ret[pos / c][pos % c] = a[i][j];
            }
        }
        return ret;
    }
};
