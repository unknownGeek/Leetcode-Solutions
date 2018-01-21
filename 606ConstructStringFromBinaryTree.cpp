//606. Construct String from Binary Tree
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
    string tree2str(TreeNode* t) {
        string result="";
        dfs(t, result);
        return result;

    }

    void dfs(TreeNode* node, string& s)
    {
        if(!node)
         {
             return;
        }
        s+=to_string(node->val);

        if(node->left || node->right)
        {
            s+='(';
            dfs(node->left, s);
            s+=')';

         if(node->right)
            {
                s+='(';
                dfs(node->right, s);
                s+=')';
            }
        }
    }

};
