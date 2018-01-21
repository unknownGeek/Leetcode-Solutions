/**
496. Next Greater Element I ::
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next
greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist,
output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
**/
//Version 1 ::
class Solution {
public:
    #define inf 1234567
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(nums.empty())return {};
        int n = nums.size();
        vector<int> ans;
        nums.push_back(inf);
        stack<int> s;
        s.push(nums[0]);
        map<int, int> lol;
        for(int i=1; i<=n; ++i){
            if(s.top() < nums[i]){
                while(!s.empty()){
                    int x = s.top();
                    if(x>nums[i])break;
                    s.pop();
                    lol[x] = nums[i]==inf ? -1 : nums[i];
                }
                s.push(nums[i]);
            }
            else{
                s.push(nums[i]);
            }
        }
        for(int num : findNums){
            ans.push_back(lol[num]);
        }
        return ans;
    }
};

//Version 2::
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = nums.size();
        map<int, int> ans;
        for(int i = 0; i < n; i++)
        {
            ans[nums[i]] = -1;
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] < nums[j])
                {
                    ans[nums[i]] = nums[j];
                    break;
                }
            }
        }
        vector<int> va;
        for(int x: findNums)
            va.push_back(ans[x]);
        return va;
    }
};

//Version 3::
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for (auto x : findNums) {
            bool ok = false;
            int next = -1;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == x) ok = true; else if (ok && nums[i] > x) {
                    next = nums[i];
                    break;
                }
            }
            res.push_back(next);
        }
        return res;
    }
};



//Version 4::
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> M;
        set<int> S;
        int n = nums.size();
        for (int i = n-1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++)
                if (nums[j] > nums[i]) {
                    M[nums[i]] = nums[j];
                    break;
                }
        }
        vector<int> re;
        for (int i = 0; i < findNums.size(); i++)
        {
            int k = findNums[i];
            if (M.find(k) == M.end())
                re.push_back(-1);
            else
                re.push_back(M[k]);
        }
        return re;
    }
};


//Version 5::
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] = i;
        }
        vector<int> res;
        for(int i=0;i<findNums.size();i++)
        {
            int a = -1;
            for(int j=m[findNums[i]];j<nums.size();j++)
            {
                if(nums[j]>findNums[i])
                {
                    a=nums[j];
                    break;
                }
            }
            res.push_back(a);
        }
        return res;
    }
};
