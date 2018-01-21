/**
Equal Tree Partition::
Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation:
    5
   /
  10

Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
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
        bool isEqual;
    int getTotalSum(TreeNode* node)
        {
             if(!node)return 0;
             return node->val + getTotalSum(node->left) + getTotalSum(node->right);
        }
    int getSum(TreeNode* node, int targetSum)
    {
        if(!node)return 0;
        int currSum = node->val + getSum(node->left, targetSum) + getSum(node->right, targetSum);
        if(currSum == targetSum)
            isEqual = true;
        return currSum;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        if(!root)return false;
        if(!root->left && !root->right && root->val==0)return false;
        int totalSum = getTotalSum(root);
        if(totalSum&1)return false; //if totalSum is not even, then we can't split tree into two equal half-sums
        isEqual = false;
        getSum(root, totalSum>>1);// check whether there is a subtree having half-sum of the whole tree or not
        return isEqual;
    }
};
