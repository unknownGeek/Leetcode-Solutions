/*
769. Max Chunks To Make Sorted (ver. 1) ::
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
*/


/*
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int l, r;
        l=r= n-1;
        int i = n-1, j;
        bool visited[n+1]={false};
        function<bool(int, int)> check;
        check = [&] (int a, int b) ->bool{
            for(int i=a; i<=b; ++i){
                if(!visited[i]){
                    return false;
                }
            }
            return true;
        };
        while(i>=0){
            visited[i] = true;
            l = min(l, arr[i]);
            if(check(l, r)){
                ++cnt;
                l=r=l-1;
            }
            --i;
        }
        return cnt;
    }
};*/



class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mx = -1e9;
        int n = arr.size();
        int cnt = 0;
        int currmax = -1e9;
        int currmin = +1e9;
        for (int i = 0; i < n; ++i) {        
            currmax = max(currmax, arr[i]);
            bool valid = true;
            for (int j = i+1; j < n; ++j) {
                if (arr[j] < currmax) {
                    valid = false;
                    break;
                }
            }

            if (valid){
                currmax = -1e9;
                ++cnt;                
            }            
        }
        return cnt;    
    }
};