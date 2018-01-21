/**
530. Minimum Absolute Difference in BST ::
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
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



//Version 1::
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
       if(!root)return 0;
        vector<int> nums;
        function<void(TreeNode*)> dfs;
        dfs = [&] (TreeNode* node){
            if(!node)return;
            dfs(node->left);
            nums.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0; i<n-1; ++i)
            ans = min(ans, abs(nums[i]-nums[i+1]));
        return ans;
    }
};

//Version 2::
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int answer = INT_MAX, last = -1;
        function<void(TreeNode*)> dfs;
        dfs = [&] (TreeNode* root){
        if (!root)return;
            dfs(root->left);
            if (last != -1)
                    answer = min(answer, root->val - last);
            last = root->val;
            dfs(root->right);
       };
        dfs( root );
        return answer;
    }
};


