/*
404. Sum of Left Leaves::

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        int leftSum=0;
        if(root->left)
        {
            if(!root->left->left && !root->left->right)
                 leftSum=root->left->val;
            else
                leftSum=sumOfLeftLeaves(root->left);
        }
        return leftSum+sumOfLeftLeaves(root->right);
    }
};
