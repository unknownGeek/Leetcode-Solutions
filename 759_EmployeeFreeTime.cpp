/*
759. Employee Free Time ::
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

Note:

schedule and schedule[i] are lists with lengths in range [1, 50].
0 <= schedule[i].start < schedule[i].end <= 10^8.
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> times, ans;
        for(vector<Interval> &employee : schedule){
            for(Interval &interval : employee){
                times.push_back(interval);
            }
        }
        sort(times.begin(), times.end(), [](Interval &a, Interval &b){
            return (a.start != b.start) ? (a.start < b.start) : (a.end < b.end); 
        });
        stack<Interval> s;
        for(Interval &interval : times){
            if(s.empty()){
                s.push(interval);
            }else{
                Interval prev = s.top();
                if(prev.end >= interval.start){
                    if(interval.end > prev.end){
                        Interval newInterval = Interval(prev.start, interval.end);
                        s.pop();
                        s.push(newInterval);
                  }else{
                        continue;
                    }
                }else{
                    s.push(interval);
                }
            }
        }
       times.clear();
       while(!s.empty()){
            times.push_back(s.top());
            s.pop();
       }
       reverse(times.begin(), times.end());
       int n = times.size();
       for(int i=1; i<n; ++i){
         if(times[i].start > times[i-1].end){
             ans.push_back(Interval(times[i-1].end, times[i].start));
         }  
       }
      return ans;  
    }
};