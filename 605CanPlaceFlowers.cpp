//605. Can Place Flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int size = flowerbed.size();
        int cnt=0;
        for(int i=1;i<size-1;++i)
           if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
                    {
                        ++cnt;
                        flowerbed[i]=1;
                    }



     return (cnt>=n);



     /* int cnt=0;
      if(flowerbed[0]==0 && flowerbed[1]==0)
           {
               ++cnt;
               flowerbed[0]=1;
           }
      int size = flowerbed.size();
        for(int i=1;i<size-1;++i)
           if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
                    {
                        ++cnt;
                        flowerbed[i]=1;
                    }

           if(flowerbed[size-2]==0 && flowerbed[size-1]==0)
           {
               ++cnt;
               flowerbed[size-1]=1;
           }


     return (cnt>=n);  */


    }
};
