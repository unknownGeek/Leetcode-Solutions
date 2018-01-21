/*
766. Toeplitz Matrix::
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
*/

/*class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return false;
        }
        for(auto &row : matrix){
            reverse(row.begin(), row.end());
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        //O(m*n)
        vector<int> tmp[n+m-1];
        for (int i = 0; i < n+m-1 ; ++i) {
            int row = max(0, i-(m-1));
            int col = min(i, m-1);
            while(row < n && col >= 0){
                tmp[i].push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }
        for(auto vec : tmp){
            int unique = vec[0];
            for(int num : vec){
                if(num != unique){
                   // return false;
                }
                cout<<num<<" ";
            }
            cout<<'\n';
        }
     return true;   
    }
};
*/

/*

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
	        for(int i = 0;i < n-1; ++i){
	        	for(int j = 0;j < m-1; ++j){
	        		if(matrix[i][j] != matrix[i+1][j+1]){
                        return false;
                    }
	        	}
	        }
	        return true;
    }
};*/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return false;
        }
        for(auto &row : matrix){
            reverse(row.begin(), row.end());
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        //O(n*m(n+m-1)) 
        vector<int> tmp[n+m-1];
        for (int l = 0; l < n+m-1 ; ++l) {
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    if(i+j == l){
                        tmp[l].push_back(matrix[i][j]);
                    }
                }
            }   
        }
        for(auto vec : tmp){
            int unique = vec[0];
            for(int num : vec){
                if(num != unique){
                    return false;
                }
                cout<<num<<" ";
            }
            cout<<'\n';
        }
     return true;   
    }
};
