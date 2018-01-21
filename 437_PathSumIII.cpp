/**
437. Path Sum III ::
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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
//Version 1 ::
class Solution {
private:
    int cnt;
    void dfs(TreeNode* root, int need){
        if(!root)return;
        dfs2(root, need - root->val);
        dfs(root->left, need);
        dfs(root->right, need);
    }
    void dfs2(TreeNode* root, int need){
        if(!root)return;
        if(!need)++cnt;
        if(root->left)dfs2(root->left, need - root->left->val);
        if(root->right)dfs2(root->right, need - root->right->val);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        cnt = 0;
        dfs(root, sum);
        return cnt;
    }
};
**/

/**
//Version 2 ::
class Solution {
private:
    int dfs(TreeNode* root, int sum){
        return !root ? 0 : (sum == root->val) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        return !root ? 0 : dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
**/

//Version 3 ::
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) { return 0; }
        int ans = Dfs(root, sum);
        if (root->left != NULL) {
            ans += pathSum(root->left, sum);
        }
        if (root->right != NULL) {
            ans += pathSum(root->right, sum);
        }
        return ans;
    }
    int Dfs(TreeNode* root, int sum) {
        sum -= root->val;
        int ans = 0;
        if (sum == 0) { ans++; }
        if (root->left != NULL) {
            ans += Dfs(root->left, sum);
        }
        if (root->right != NULL) {
            ans += Dfs(root->right, sum);
        }
        return ans;
    }
};
