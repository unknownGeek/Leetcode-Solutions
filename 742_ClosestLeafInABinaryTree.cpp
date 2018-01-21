/*
742. Closest Leaf in a Binary Tree ::
Given a binary tree where every node has a unique value, and a target key k, find the value of the closest leaf node to target k in the tree.

Here, closest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the closest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The closest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is closest to the node with value 2.
Note:
root represents a binary tree with at least 1 node and at most 1000 nodes.
Every node has a unique node.val in range [1, 1000].
There exists some node in the given binary tree for which node.val == k.
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
public:
    int findClosestLeaf(TreeNode* root, int k) {
        #define N 1005
        vector<int> adj[N];
        bool isLeaf[N];
        memset(isLeaf, false, sizeof isLeaf);
        int value = -1;
        int minDistance = INT_MAX;
        function<void(TreeNode*)> dfs;
        dfs = [&] (TreeNode* root) -> void{
            if(!root)return;
            isLeaf[root->val] = (!root->left && !root->right);
            if(root->left){
                adj[root->val].push_back(root->left->val);
                adj[root->left->val].push_back(root->val);
            }
            
            if(root->right){
                adj[root->val].push_back(root->right->val);
                adj[root->right->val].push_back(root->val);
            }
            dfs(root->left);
            dfs(root->right);
        };
        
        function<void(int, int, int)> dfs2;
        dfs2 = [&] (int curr, int par, int dist) -> void{
            if(isLeaf[curr]){
                if(minDistance > dist){
                    minDistance = dist;
                    value = curr;
                }
            }
            
            for(int nextValue : adj[curr]){
                if(nextValue == par){
                    continue;
                }
                dfs2(nextValue, curr, dist+1);
            }
        };
        dfs(root);
        dfs2(k, -1, 0);
        return value;
    }
};