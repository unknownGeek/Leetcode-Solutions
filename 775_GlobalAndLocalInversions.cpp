/*
775. Global and Local Inversions ::
We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

*/


/*
//Version#1 ::
class Solution {
public:
    int merge(int arr[], int temp[], int left, int mid, int right){
      int i, j, k;
      int inv_count = 0;

      i = left; 
      j = mid; 
      k = left; 
      while ((i <= mid - 1) && (j <= right))
      {
        if (arr[i] <= arr[j])
        {
          temp[k++] = arr[i++];
        }
        else
        {
          temp[k++] = arr[j++];

          inv_count = inv_count + (mid - i);
        }
      }


        while (i <= mid - 1)
        temp[k++] = arr[i++];


        while (j <= right)
        temp[k++] = arr[j++];

        for (i=left; i <= right; i++)
        arr[i] = temp[i];

      return inv_count;
    }
    
    int _mergeSort(int arr[], int temp[], int left, int right){
      int mid, inv_count = 0;
      if (right > left)
      {
        
          mid = (right + left)/2;

        
          inv_count  = _mergeSort(arr, temp, left, mid);
          inv_count += _mergeSort(arr, temp, mid+1, right);

         inv_count += merge(arr, temp, left, mid+1, right);
      }
      return inv_count;
    }

    int mergeSort(int arr[], int array_size){
        int *temp = (int *)malloc(sizeof(int)*array_size);
        return _mergeSort(arr, temp, 0, array_size - 1);
    }
 
    bool isIdealPermutation(vector<int>& a) {
        int n = a.size();
        int arr[n+1];
        for(int i=0; i<n; ++i){
            arr[i] = a[i];
        }
        int c = mergeSort(arr, n);
        
        for(int i=0; i<n-1; ++i){
            if(a[i] > a[i+1]){
                --c;
            }    
        }
        return c==0;
    }
};*/




/*
//Version#2 ::
class Solution {
public:
    bool isIdealPermutation(vector<int> &A) {
       for (int i = 0; i < A.size(); i++) {
            if (abs(A[i] - i) > 1){
                return false;
            }
        }
        return true;
    }
};*/


//Version#3 :: Fenwick Tree or BIT
class Solution {
public:
  const int N = 10000;
  bool isIdealPermutation(vector<int> &A) {
    tr.resize(N);
    int local = 0;
    for (int i = 1; i < A.size(); ++i) {
      local += A[i - 1] > A[i];
    }
    int global = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
      int x = A[i];
      ++x;
      global += get(x);
      add(x);
    }
    return global == local;
  }

  vector<int> tr;
  void add(int x) {
    for (; x < N; x += x & -x) {
      ++tr[x];
    }
  }

  int get(int x) {
    int s = 0;
    for (; x; x -= x & -x) {
      s += tr[x];
    }
    return s;
  }
};
