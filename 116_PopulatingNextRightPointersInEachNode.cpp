/**
116. Populating Next Right Pointers in Each Node ::
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
**/



/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
Version 1 :: Using Extra Space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; ++i){
                TreeLinkNode* curr = q.front();q.pop();
                if(i==n-1){
                    curr->next = nullptr;
                }
                else{
                    curr->next = q.front();
                }
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
    }
};
*/


/*
//Version 2::O(1)space Iterative
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        TreeLinkNode *pre = root;
        TreeLinkNode *curr = nullptr;
        while(pre->left){
            curr = pre;
            while(curr){
                curr->left->next = curr->right;
                if(curr->next) curr->right->next = curr->next->left;
                curr = curr->next;
            }
            pre = pre->left;
        }
    }
};
*/

//Version 3 :: O(1)space recursive
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        if(root->left){
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);
    }
};





