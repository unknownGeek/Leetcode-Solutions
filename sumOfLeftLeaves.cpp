/**
404. Sum of Left Leaves ::
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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

//Version 1 ::
class Solution {
private:
    int ans;
    void dfs(TreeNode* node){
        if(!node)return;
        if(node->left && !node->left->left && !node->left->right){
            ans += node->left->val;
            return dfs(node->right);
        }
        dfs(node->left);
        dfs(node->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};



//Version 2::
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right)
                sum = root->left->val;
            else
                sum = sumOfLeftLeaves(root->left);
        }
        return sum + sumOfLeftLeaves(root->right);
    }
};


//Version 3::
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (!root) return 0;
        if (!root->left && !root->right && isLeft) return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
