/**
350. Intersection of Two Arrays II ::
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the
memory at once?
**/
//Version 1::
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> lol;
        vector<int> res;
        for(int num : nums1)
            ++lol[num];
        for(int num : nums2)
            if(--lol[num] >= 0)
                res.push_back(num);
        return res;
    }
};


//Version 2::
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> lol;
        vector<int> res;
        for(int num : nums1)
            ++lol[num];
        for(int num : nums2)
            if(lol.find(num)!=lol.end() && --lol[num] >= 0)
                res.push_back(num);
        return res;
    }
};

//Version 3::
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = (int)nums1.size(), m = (int)nums2.size();
        int i = 0, j = 0;
        vector<int> res;
        while(i < n && j < m){
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            }
            else if(nums1[i] > nums2[j])
                ++j;
            else
                ++i;
        }
        return res;
    }
};
