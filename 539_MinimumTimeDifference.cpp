/**
539. Minimum Time Difference ::
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any
two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
**/

/*
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> a;
        for (string s : timePoints)
            a.push_back(((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0'));
        int ans = 1000000;
        int day = 24*60;
        for (int i = 0; i < a.size(); ++i)
            for (int j = i+1; j < a.size(); ++j)
            {
                int tmp = a[i]-a[j];
                if (tmp < 0) tmp += day;
                if (ans > tmp) ans = tmp;
                if (ans > day-tmp) ans = day-tmp;
            }
        return ans;
    }
};*/


/*
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (auto t : timePoints) {
            int h, m;
            sscanf(t.c_str(), "%d:%d", &h, &m);
            v.push_back(h * 60 + m);
            v.push_back(h * 60 + m + 24 * 60);
        }
        sort(v.begin(), v.end());
        int ans = v[1] - v[0];
        for (size_t i = 1; i < v.size(); i++) ans = min(ans, v[i] - v[i - 1]);
        return ans;
    }
};*/

/*
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            string s = timePoints[i];
            int k = s.find(":");
            int x = atoi(s.substr(0, k).c_str());
            int y = atoi(s.substr(k+1).c_str());
           // cout << x << " " << " " << y << endl;
            A.push_back(x*60+y);
            A.push_back((x+24)*60+y);
        }
        sort(A.begin(),A.end());
        //A.push_back(A[0]);
        int ans = INT_MAX;
        for (int i = 1; i < A.size(); i++)
            ans = min(ans, A[i]-A[i-1]);
        return ans;
    }
};*/class Solution {
public:
    int findMinDifference(vector<string>& t) {
        int n = t.size();
        vector<int> a(n * 2);
        for (int i = 0; i < n; ++i) {
            int x = (t[i][0] - '0') * 10 + (t[i][1] - '0');
            int y = (t[i][3] - '0') * 10 + (t[i][4] - '0');
            a[i] = x * 60 + y;
            a[i + n] = a[i] + 60 * 24;
        }
        sort(a.begin(), a.end());
        int ret = 1 << 30;
        for (int i = 1; i < a.size(); ++i) {
            ret = min(ret, a[i] - a[i - 1]);
        }
        return ret;
    }
};
