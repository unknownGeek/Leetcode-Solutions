/**
543. Diameter of Binary Tree::
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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

/**
We can solve this problem with two different cases:

1) If the longest path will include the root node, then the longest path must be the depth(root->right) + depth (root->left)
2) If the longest path does not include the root node, this problem is divided into 2 sub-problem: set left child and right child as the new root separately, and repeat step1.
We could get the solution by returning the max path of 1 and 2.
**/
class Solution {
private:
    int depth(TreeNode* node)
    {
        if(!node)return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int res=depth(root->left)+depth(root->right);//when we include root of the tree
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};




class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs;
        dfs = [&] (TreeNode* root){
            if(!root)return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            ans = max(ans, l+r);

            return 1+ max(l, r);
        };
        dfs(root);
        return ans;
    }
};
