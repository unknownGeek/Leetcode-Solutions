/**
654. Maximum Binary Tree::
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

1) The root is the maximum number in the array.
2) The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
3) The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
Note: The size of the given array will be in the range [1,1000].

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
    TreeNode* build(int start, int end, vector<int> &nums)
    {
        if(end<start)
             return nullptr;
        if(start==end)return new TreeNode(nums[start]);
        int maximum = INT_MIN;
        int maxIndex=-1;
        for(int i=start; i<=end; ++i)
        {
         if(maximum<nums[i])
         {
             maximum=nums[i];
             maxIndex=i;
         }
        }
        TreeNode* root = new TreeNode(maximum);
        root->left = build(start, maxIndex-1, nums);
        root->right = build(maxIndex+1, end, nums);
        return root;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size()-1, nums);
    }
};
