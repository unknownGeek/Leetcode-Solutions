/*
768. Max Chunks to Make Sorted (ver. 2) ::
This question is the same as "Max Chunks to Make Sorted (ver. 1)" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 2000].
arr[i] will be an integer in range [0, 10**8].
*/


/*class Solution {
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

*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i , n = arr.size() , ans = 0;
    	int *mininum = new int[n];
    	for (i = n - 1;i >= 0;i --) {
    		if (i == n - 1) {
    			mininum[i] = arr[i];
    		} else {
    			mininum[i] = min<int>(mininum[i + 1] , arr[i]);
    		}
    	}
    	int maximum = -1e9;
    	for (i = 0;i < n; ++i) {
    		if (arr[i] > maximum) {
    			maximum = arr[i];
    		}
    		if (i + 1 == n) {
    			++ans;
    		} else {
    			if (maximum <= mininum[i + 1]) {
    				maximum = - 1;
    				++ans;
    			}
    		}
    	}
    	return ans;
    }
};





