/**
257. Binary Tree Paths ::
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        function<void(TreeNode*, string)> dfs;
        dfs = [&] (TreeNode* root, string curr) -> void{
            if(!root)return;
            if(!root->left && !root->right){
                ans.push_back((curr.empty())? curr+to_string(root->val) : curr+"->"+to_string(root->val));
                return;
            }

            dfs(root->left,  (curr.empty())? curr+to_string(root->val) : curr+"->"+to_string(root->val));
            dfs(root->right, (curr.empty())? curr+to_string(root->val) : curr+"->"+to_string(root->val));
        };
        string curr("");
        dfs(root, curr);
        return ans;
    }
};



//Version 2::
class Solution {
public:
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;
    function<void(TreeNode*, string)> binaryTreePaths;
    binaryTreePaths = [&] (TreeNode* root, string t) ->void {
        if(!root->left && !root->right) {
            result.push_back(t);
            return;
        }

        if(root->left) binaryTreePaths(root->left, t + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(root->right, t + "->" + to_string(root->right->val));
    };
    binaryTreePaths(root, to_string(root->val));
    return result;
  }
};



//Version 3::
class Solution {
public:
      vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root) return paths;

        if(!root->left && !root->right){
            paths.push_back(to_string(root->val));
            return paths;
        }

         for(string path : binaryTreePaths(root->left))
             paths.push_back(to_string(root->val) + "->" + path);

         for(string path : binaryTreePaths(root->right))
             paths.push_back(to_string(root->val) + "->" + path);
         return paths;
   }
};
