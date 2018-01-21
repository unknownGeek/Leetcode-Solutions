/**
501. Find Mode in Binary Search Tree ::
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion
does not count).
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
private:
    map<int, int> lol;
    void preorder(TreeNode* root){
        if(!root)return;
        ++lol[root->val];
        preorder(root->left);
        preorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        if(!root)return {};
        preorder(root);
        int mx = 0;
        for(auto it : lol)
            mx = max(mx, it.second);
        vector<int> ans;
         for(auto it : lol)
            if(it.second == mx)
                ans.push_back(it.first);
        return ans;
    }
};
