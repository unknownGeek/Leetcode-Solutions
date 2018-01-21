/**
658. Find K Closest Elements
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 10^4
Absolute value of elements in the array and x will not exceed 10^4
**/
/**

//Version 1 :: Best Solution Ever!
int y;
bool cmp(const int& a, const int& b) {
    if (abs(a - y) != abs(b - y))
        return abs(a - y) < abs(b - y);
    return a < b;
}

class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        y = x;
        sort(arr.begin(), arr.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(arr[i]);
        sort(res.begin(), res.end());
        return res;
    }
};
**/

/**
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define dd(x) cerr << #x << " = " << x << ", "
#define de(x) cerr << #x << " = " << x << endl
//-------
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    	vector<int> ret;
    	set<pair<int, int> > S;
    	set<pair<int, int> >::iterator it;
    	rep(i, 0, sz(arr))
    		S.insert(mp(abs(arr[i] - x), i));
    	for (it = S.begin(); k > 0 && it != S.end(); ++it) {
    		--k;
    		ret.pb(arr[it->se]);
    	}
    	sort(all(ret));
    	return ret;
    }
};**/


/**
class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size();
        vector<pair<int, int>> A;
        for (int i = 0; i < n; ++i) {
            A.push_back(make_pair(abs(a[i] - x), a[i]));
        }
        sort(A.begin(), A.end());
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(A[i].second);
        }
        sort(ret.begin(), ret.end());
        return ret;

    }
};
**/


/**
    class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1;
        vector<int> temp;
        while (i <= j) {
            if (abs(arr[i] - x) > abs(arr[j] - x)) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j--]);
            }
        }

        reverse(temp.begin(), temp.end());

        vector<int> ans = vector<int>(temp.begin(), temp.begin() + k);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
**/



/**
    struct comp {
  bool operator() (int a, int b) {
    return abs(a) != abs(b) ? abs(a) > abs(b) : a > b;
  }
};

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<int, vector<int>, comp> pq;
    for (int num : arr) {
      pq.push(num - x);
    }
    vector<int> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(pq.top() + x);
      pq.pop();
    }
    sort(result.begin(), result.end());
    return result;
  }
};**/


/**
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, const int k, const int x) {
        sort(arr.begin(), arr.end(), [x](const int a, const int b){
            const int d1 = abs(a - x);
            const int d2 = abs(b - x);
            if (d1 != d2) return d1 < d2;
            return a < b;
        });

        vector<int> ret(arr.begin(), arr.begin() + k);
        sort(ret.begin(), ret.end());
        return ret;
    }
};**/

class Solution {
    int bs(vector<int>& arr, int low, int high, int x) {
        if (arr[high] <= x) return high;
        if (arr[low] > x) return low;
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x)
            return mid;
        if (arr[mid] < x)
            return bs(arr, mid + 1, high, x);
        return bs(arr, low, mid - 1, x);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        if (k == 0) return ans;
        int l = bs(arr, 0, n - 1, x);
        int r = l + 1;
        int count = 0;
        if (arr[l] == x) {
            l--;
            r--;
        }
        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] <= arr[r] - x)
                ans.push_back(arr[l]), l--;
            else
                ans.push_back(arr[r]), r++;
            count++;
        }
        while (count < k && l >= 0) {
            ans.push_back(arr[l]), l--;
            count++;
        }
        while (count < k && r < n) {
            ans.push_back(arr[r]), r++;
            count++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
