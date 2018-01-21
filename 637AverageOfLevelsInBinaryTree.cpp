/*637. Average of Levels in Binary Tree::

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<double> sumOfLevel;
    vector<int>   sizeOfLevel;
    void dfs(TreeNode* node, int depth)
    {
        if(!node)return;
        if(depth >= sumOfLevel.size())
        {
            sumOfLevel.push_back(0);
           sizeOfLevel.push_back(0);
        }
         sumOfLevel[depth]+= node->val;
       ++sizeOfLevel[depth];
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        for(int i=0; i<sumOfLevel.size(); ++i)
            sumOfLevel[i]/=sizeOfLevel[i];
        return sumOfLevel;
    }
};
