/**
108. Convert Sorted Array to Binary Search Tree ::
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums){
        function<TreeNode*(int, int)> build;
        build = [&] (int l, int r) -> TreeNode*{
            if(l>r)return nullptr;
            int mid = l + ((r-l)>>1);
            TreeNode *root = new TreeNode(nums[mid]);
            if(l==r)return root;
            root->left  = build(l, mid-1);
            root->right = build(mid+1, r);
            return root;
        };
        return build(0, nums.size()-1);
    }
};


//version 2::
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if(nums.empty()) return nullptr;
        int n = nums.size();
        if(n == 1)
            return new TreeNode(nums[0]);

        int mid = n>>1;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> leftInts(nums.begin(), nums.begin()+mid);
        vector<int> rightInts(nums.begin()+mid+1, nums.end());

        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);

        return root;
    }
};
