/**
581. Shortest Unsorted Continuous Subarray ::
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending
order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
**/

/*class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
            if(nums.empty())return 0;
            int n = nums.size();
            vector<int> a(nums);
	        sort(a.begin(), a.end());
	        if(a == nums)
	        	return 0;
	        int len = n;
	        for(int i=0; i<n; ++i){
	        	if(a[i] == nums[i]){
	        		--len;
	        	}else{
	        		break;
	        	}
	        }
	        for(int i=n-1; i >= 0; --i){
	        	if(a[i] == nums[i]){
	        		--len;
	        	}else{
	        		break;
	        	}
	        }
	        return len;

    }
};*/


/*
class Solution {
public:
    int findUnsortedSubarray(vector<int> a) {
        vector<pair<int,int> > b;
        int n=a.size();
        for ( int i=0; i<n; i++ ) b.push_back(make_pair(a[i],i));
        sort(b.begin(),b.end());
        int mi=n,mx=0;
        for ( int i=0; i<n; i++ ) if ( b[i].second!=i ) mi=min(mi,b[i].second),mx=max(mx,b[i].second);
        if ( mi==n ) return 0;
        else return mx-mi+1;
    }
};*/

class Solution {
public:
  int findUnsortedSubarray(vector<int>& a) {
    vector<int> b(a);
    sort(b.begin(), b.end());
    int l = 0, r = a.size();
    while (l < r && a[l] == b[l]) ++l;
    while (l < r && a[r-1] == b[r-1]) --r;
    return r-l;
  }
};
