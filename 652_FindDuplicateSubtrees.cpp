/*
652. Find Duplicate Subtrees::

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.

*/

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
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>> &map)
    {
        if(!node)return string("");
        string s = "("+serialize(node->left, map)+to_string(node->val)+serialize(node->right, map)+")";
        map[s].push_back(node);
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
     unordered_map<string, vector<TreeNode*>> map;
     vector<TreeNode*> results;
     serialize(root, map);
     for(auto entry : map)
         if(entry.second.size()>1)
               results.push_back(entry.second[0]);
    return results;
    }
};
