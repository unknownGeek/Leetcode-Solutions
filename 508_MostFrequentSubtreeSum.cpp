/**
508. Most Frequent Subtree Sum ::
Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the
sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent
subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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


//Version 1 ::
class Solution {
private:
    long mx;
    map<long, int> lol;
    long subtreeSum(TreeNode* root){
        if(!root)return 0;
        int l = subtreeSum(root->left);
        int r = subtreeSum(root->right);
        mx = max(mx, (long)++lol[(long)(l+r+root->val)]);
        return (long)(l+r+root->val);
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root)return {};
        mx = LONG_MIN;
        subtreeSum(root);
        vector<int> ans;
        for(auto it : lol){
            if(it.second == mx)
                ans.push_back(it.first);
        }
        return ans;
    }
};

//Version 2::
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> lol;
        function<int(TreeNode *)> dfs;
        dfs = [&] (TreeNode *root) {
            if (!root)
                return 0;
            int sum = root->val;
            sum += dfs(root->left);
            sum += dfs(root->right);
            ++lol[sum];
            return sum;
        };
        dfs(root);
        int mx = 0;
        vector<int> ans;
        for (auto it : lol)
            if (it.second > mx)
                mx = it.second;

        for (auto it : lol)
            if (it.second == mx)
                ans.push_back(it.first);

        return ans;
    }
};
