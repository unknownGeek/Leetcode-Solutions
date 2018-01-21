/**
513. Find Bottom Left Tree Value::
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

**/
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
public:
    int findBottomLeftValue(TreeNode* root) {
        int res=-1;
        if(!root)return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
             res=q.front()->val;
            int n=q.size();
            for(int i=0; i<n; ++i)
            {
                TreeNode* node = q.front();q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);

            }
        }
        return res;
    }
};
