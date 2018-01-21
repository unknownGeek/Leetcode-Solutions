/**
226. Invert Binary Tree ::
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};



//Version 2::
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);
        root->left  = r;
        root->right = l;
        return root;
    }
};




//Version 3::
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};




//Version 4:: DFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();s.pop();
            if(!curr)continue;
            s.push(curr->left);
            s.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};



//Version 5:: BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
            TreeNode* curr = q.front();q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            swap(curr->left, curr->right);
            }
        }
        return root;
    }
};
