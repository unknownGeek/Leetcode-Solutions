/**
513. Find Bottom Left Tree Value ::
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
        if(!root)return -1;
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; ++i){
                TreeNode* curr = q.front();q.pop();
                if(i==0)
                    ans = curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return ans;
    }
};


class Solution {
public:
    map<int, vector<TreeNode *> > S;
    void dfs(TreeNode *root, int d)
    {
        if(!root)
            return;
        S[d].push_back(root);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        S.clear();
        dfs(root, 0);
        return (--S.end())->second.front()->val;
    }
};
