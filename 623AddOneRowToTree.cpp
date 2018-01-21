//623. Add One Row to Tree
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
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
          if(!root)return root;
          if(d==1)
          {
            TreeNode *x = new TreeNode(v);
            x->left = root;
            return x;
          }
        dfs(root, 1, d, v);
        return root;
    }

    void dfs(TreeNode* node, int currDepth, const int& d, const int& v)
    {
        if(!node)return;
        else if(currDepth==d-1)
         {
             TreeNode* l=node->left;
             TreeNode* r=node->right;
             TreeNode* x=new TreeNode(v);
             node->left=x;
             x->left=l;
             TreeNode* y=new TreeNode(v);
             node->right=y;
             y->right=r;
             return;
         }
          dfs(node->left, currDepth+1, d, v);
          dfs(node->right, currDepth+1, d, v);
    }

};
