/*
99. Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    TreeNode* firstNode=nullptr;
    TreeNode* secondNode=nullptr;
    TreeNode* previousNode = new TreeNode(INT_MIN);

    void inorder(TreeNode* node)
    {
        if(!node)return;
        inorder(node->left);

   //do some business
    // Start of "do some business",
            // If firstNode has not been found, assign it to previousNode
            if(!firstNode &&  previousNode->val >=node->val )
                 firstNode = previousNode;
              // If firstNode is found, assign the secondNode to the root
            if(firstNode &&  previousNode->val >= node->val)
                  secondNode = node;
            previousNode = node;
    // End of "do some business"

        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(firstNode->val, secondNode-> val);
    }
};
