/**
398. Random Pick Index
Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that
the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
**/


//Version 1 ::
typedef pair<int, int> pii;
class Solution {
private:
    vector<pii> A;
    int rand32()
    {
    	static const int m = 32768;
    	int r0 = rand() % m;
    	int r1 = rand() % m;
    	return r1 * m + r0;
    }
public:
    Solution(vector<int> nums) {
        int n = nums.size();
        A.resize(n);
        for(int i=0; i<n; ++i)
            A[i] = pii(nums[i], i);
        sort(A.begin(), A.end());
    }

    int pick(int target) {
        int l = lower_bound( A.begin(), A.end(), pii(target,  0) ) - A.begin();
        int r = lower_bound( A.begin(), A.end(), pii(target,2e9) ) - A.begin();
        int p = rand32() % (r-l) + l;
        return A[p].second;
    }
};



//Version 2 ::
class Solution {
public:
    vector<int> a;
    Solution(vector<int> nums) {
        a = nums;
    }

    int pick(int target) {
        int cnt = 0;
        int result = 0;
        for (int i = 0 ; i < a.size() ; ++i) {
            if (a[i] == target) {
                ++cnt;
                if (rand() % cnt == 0) result = i;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
