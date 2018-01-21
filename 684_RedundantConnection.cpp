/**
684. Redundant Connection ::
We are given a "tree" in the form of a 2D-array, with distinct values for each node.

In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.

We can remove exactly one redundant pair in this "tree" to make the result a tree.

You need to find and output such a pair. If there are multiple answers for this question, output the one appearing last in the 2D-array. There is always at least one answer.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: Original tree will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [1,3], [3,1]]
Output: [3,1]
Explanation: Original tree will be like this:
  1
 / \\
2   3
Note:
The size of the input 2D-array will be between 1 and 1000.
Every integer represented in the 2D-array will be between 1 and 2000.
**/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
      int i,j,k,n,x,y,tmp;
      vector<int> ans;
      n=edges.size();
      int parent[2002];
      for (i=0;i<2002;i++)
          parent[i]=i;
      for (i=0;i<n;i++)
      {
        x=edges[i][0];
        y=edges[i][1];
        if (parent[x]==parent[y])
            return edges[i];
        tmp=parent[y];
        for (j=0;j<2002;j++)
          if (parent[j]==tmp)
                parent[j]=parent[x];
      }
      return ans;
    }
};
