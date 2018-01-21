/**
475. Heaters ::
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses
could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius
standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be
warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be
warmed.
**/

//Version 1::
class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int standardRadius = 0;
    sort(heaters.begin(), heaters.end());
    sort(houses.begin(), houses.end());
    for (int housePosition : houses) {
      auto heaterPositionIterator = lower_bound(heaters.begin(), heaters.end(), housePosition);
      int distance_from_one_neighbor_heater = INT_MAX;
      int distance_from_other_neighbor_heater  = INT_MAX;
      if (heaterPositionIterator != heaters.end())
          distance_from_one_neighbor_heater = *heaterPositionIterator - housePosition;
      if (heaterPositionIterator != heaters.begin()) {
          --heaterPositionIterator;
          distance_from_other_neighbor_heater = housePosition - *heaterPositionIterator;
      }
      int smallestDistance = min(distance_from_one_neighbor_heater, distance_from_other_neighbor_heater);
      standardRadius = max(standardRadius, smallestDistance);
    }
    return standardRadius;
  }
};




//Version 2::
class Solution {
public:
    int findRadius(vector<int> houses, vector<int> heaters) {
      set < int > st(heaters.begin(), heaters.end());
      int ans = 0;
      for (int i = 0; i < (int)houses.size(); ++i) {
        int x = houses[i];
        set < int > :: iterator it = st.lower_bound(x);
        int foo = 1.1e9;
        if (it != st.end()) {
          foo = min(foo, abs(*it - x));
        }
        if (it != st.begin()) {
          --it;
          foo = min(foo, abs(*it - x));
        }
        ans = max(ans, foo);
      }
      return ans;
    }
};


//Version 3::
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = 0;
        int i = 0;
        for(int x : houses) {
            while(i + 1 < heaters.size() and abs(x - heaters[i + 1]) <= abs(x - heaters[i]))
                i++;
            result = max(result, abs(x - heaters[i]));
        }
        return result;
    }
};
