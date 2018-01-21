/**
653. Two Sum IV - Input is a BST::
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
Discuss


**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };*//**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
//Version 1 ::
class Solution {
private:
    set<int> s;
    bool ans;
    void inorder(TreeNode* node, int& k)
    {
        if(!node)return;
        inorder(node->left, k);
        if(s.find(k-node->val)!=s.end())
             ans=true;
        s.insert(node->val);
        inorder(node->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root || !root->left && !root->right)return false;
        ans=false;
        inorder(root, k);
       return ans;
    }
};*/

/*
//version 2:
class Solution {
private:
    vector<int> nums;
    void inorder(TreeNode* node)
    {
        if(!node)return;
        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        inorder(root);
        int n = nums.size();
        int i=0, j=n-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
                return true;
            if(nums[i]+nums[j]<target)
                ++i;
            else
                --j;
        }
       return false;
    }
};*/

//Version 3 ::
class Solution {
private:
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        queue<TreeNode*> q;
        q.push(root);
            while(!q.empty())
            {
                TreeNode* node = q.front();q.pop();
                if(node)
                {
                    if(s.find(k - node->val)!=s.end())
                         return true;
                    s.insert(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        return false;
    }
};
