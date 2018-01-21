/**
Find Largest Value in Each Tree Row::
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int maximum=INT_MIN;
            for(int i=0; i<n; ++i)
            {
                TreeNode* node = q.front();q.pop();
                maximum = max(maximum, node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);

            }
            ans.push_back(maximum);
        }
     return ans;
    }
};
