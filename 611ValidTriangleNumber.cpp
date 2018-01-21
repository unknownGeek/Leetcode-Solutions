//611. Valid Triangle Number
class Solution {
public:
    int triangleNumber(vector<int>& a) {
      int i,j,k,n,left,right,mid,ans,sum;
      ans=0;
      sort(a.begin(),a.end());
      n=a.size();
      for (i=0;i<n-2;i++)
        for (j=i+1;j<n-1;j++)
        {
          sum=a[i]+a[j];
          left=j+1;right=n-1;
          while (left<=right)
          {
            mid=left+((right-left)>>1);
            if(a[mid]>=sum)
               right=mid-1;
            else
               left=mid+1;
          }
          ans+=left-j-1;
        }

      return ans;
    }


};
