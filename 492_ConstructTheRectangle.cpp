/**
492. Construct the Rectangle ::
For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular
web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following
requirements:

1. The area of the rectangular web page you designed must equal to the given target area.

2. The width W should not be larger than the length L, which means L >= W.

3. The difference between length L and width W should be as small as possible.
You need to output the length L and the width W of the web page you designed in sequence.
Example:
Input: 4
Output: [2, 2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1].
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2].
So the length L is 2, and the width W is 2.
Note:
The given area won't exceed 10,000,000 and is a positive integer
The web page's width and length you designed must be positive integers.
**/

//Version 1::
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 1;
        while((w + 1) * (w + 1) <= area) ++w;
        while(area % w) --w;
        vector<int> ans;
        ans.push_back(area / w);
        ans.push_back(w);
        return ans;
    }
};

//Version 2::
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector <int> ret;
        for (int w = 1; w*w <= area; ++w)
            if (area%w == 0)
                ret = vector<int>{area/w, w};
        return ret;
    }
};


//Version 3::
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2, 0);
        ans[0] = area;
        ans[1] = 1;
        for (int i = 2; i * i <= area; i++) {
            if (area % i == 0) {
                ans[1] = i;
                ans[0] = area / i;
            }
        }
        return ans;
    }
};

//Version 4::
class Solution {
public:
  vector<int> constructRectangle(int area) {
    for (int i = sqrt(area); i; i--)
      if (area%i == 0) {
        return {area/i, i};
      }
  }
};
