/**
107. Binary Tree Level Order Traversal II ::
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level
by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
**/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> sol;

        if(!root)
            return sol;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
             int n = q.size();
            vector<int> curr;

        for(int i = 0 ;i<n;++i)
        {

            TreeNode* current = q.front();
            q.pop();

            curr.push_back(current->val);
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);

        }

        sol.push_back(curr);
        }

        reverse(sol.begin(),sol.end());
        return sol;


    }
};
