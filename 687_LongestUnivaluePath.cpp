/**
687. Longest Univalue Path ::
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may
not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        #define inf 1234567
        function<pair<int, int>(TreeNode*)> dfs;
        dfs = [&] (TreeNode* root) -> pair<int, int>{
            if(!root)return pair<int, int>(inf, 0);
            if(!root->left && !root->right)return pair<int, int>(root->val, 1);
            pair<int, int> l = dfs(root->left);
            pair<int, int> r = dfs(root->right);
            if(l.first == r.first && l.first == root->val)
            {
                ans = max(ans, l.second+r.second);
                return pair<int, int> (root->val, 1 + max(l.second, r.second));
            }
            if(root->val == l.first){
                ans = max(ans, l.second);
                return pair<int, int> (l.first, 1 + l.second);
            }
            if(root->val == r.first){
                ans = max(ans, r.second);
                return pair<int, int> (r.first, 1 + r.second);
            }
            return pair<int, int> (root->val, 1);
        };
        dfs(root);
        return ans;
    }
};


//Version 2::
class Solution {
public:
    int solve(TreeNode* cur, int& best) {
        if (cur == nullptr) return 0;
        int L = solve(cur->left, best);
        int R = solve(cur->right, best);
        int ret = 0;
        if (cur->left && cur->left->val == cur->val) ret = max(ret, L + 1);
        if (cur->right && cur->right->val == cur->val) ret = max(ret, R + 1);
        //cout << cur->val << " " << ret << " " << L << " " << R << endl;
        int dep = 0;
        if (cur->left && cur->left->val == cur->val) dep += L + 1;
        if (cur->right && cur->right->val == cur->val) dep += R + 1;
        best = max(best, dep);
        return ret;
    }
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        solve(root, ret);
        return ret;

    }
};

//Version 3::
class Solution {
public:
    int dfs(TreeNode* root, int& val) {
        if (root == NULL) return 0;
        int a = dfs(root->left, val);
        int b = dfs(root->right, val);
        int l = 0;
        int r = 0;
        int h = 1;
        if (root->left != NULL && root->val == root->left->val) {
            h = max(h, a + 1); l = a;
        }
        if (root->right != NULL && root->val == root->right->val) {
            h = max(h, b + 1); r = b;
        }
        val = max(val, l + r);
        return h;
    }
    int longestUnivaluePath(TreeNode* root) {
        int val = 0;
        dfs(root, val);
        return val;
    }
};
