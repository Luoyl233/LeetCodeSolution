/**
 * 57. Insert Interval
 */

#include "common.h"

#if LEET_CODE == 57

class Solution {
public:
    // Not so goog.
    /*
     * Runtime: 20 ms, faster than 51.55% of C++ online submissions for Insert Interval.
     * Memory Usage: 12.5 MB, less than 50.00% of C++ online submissions for Insert Interval.
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Binary search insert position.
        int left = upper_bound(intervals.begin(), intervals.end(), newInterval,
                                  [](vector<int> x, vector<int> y) {return x[0] < y[0];}) - intervals.begin() - 1;
        int right = upper_bound(intervals.begin(), intervals.end(), newInterval,
                                     [](vector<int> x, vector<int> y) {return x[1] < y[1];}) - intervals.begin();

        // Check left.
        if (left >= 0 && newInterval[0] <= intervals[left][1]) {
            newInterval[0] = intervals[left--][0];
        }
        // Check right
        if (right < intervals.size() && intervals[right][0] <= newInterval[1]) {
            newInterval[1] = intervals[right++][1];
        }

//        printf("%d, %d", left, right);

        if (0 <= left && left < right)
            intervals.erase(intervals.begin()+left+1, intervals.begin()+right);
        intervals.insert(intervals.begin()+left+1, newInterval);
//        vector<vector<int>> res;
//        if (left >= 0)
//            res.insert(res.end(), intervals.begin(), intervals.begin()+left+1);
//        res.push_back(newInterval);
//        if (right < intervals.size())
//            res.insert(res.end(), intervals.begin()+right, intervals.end());

        return intervals;
    }

/*
 * Runtime: 16 ms, faster than 83.66% of C++ online submissions for Insert Interval.
 * Memory Usage: 12.7 MB, less than 25.00% of C++ online submissions for Insert Interval.
 */
    vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
            // Binary search insert position.
            int left = upper_bound(intervals.begin(), intervals.end(), newInterval,
                                      [](vector<int> x, vector<int> y) {return x[0] < y[0];}) - intervals.begin() - 1;
            int right = upper_bound(intervals.begin(), intervals.end(), newInterval,
                                         [](vector<int> x, vector<int> y) {return x[1] < y[1];}) - intervals.begin();

            // Check left.
            if (left >= 0 && newInterval[0] <= intervals[left][1]) {
                newInterval[0] = intervals[left--][0];
            }
            // Check right
            if (right < intervals.size() && intervals[right][0] <= newInterval[1]) {
                newInterval[1] = intervals[right++][1];
            }

           printf("%d, %d", left, right);

            if (0 <= left || right > 0)
                intervals.erase(intervals.begin()+left+1, intervals.begin()+right);
            if (intervals.size() == 0)
                intervals.push_back(newInterval);
            else
                intervals.insert(intervals.begin()+left+1, newInterval);
    //        vector<vector<int>> res;
    //        if (left >= 0)
    //            res.insert(res.end(), intervals.begin(), intervals.begin()+left+1);
    //        res.push_back(newInterval);
    //        if (right < intervals.size())
    //            res.insert(res.end(), intervals.begin()+right, intervals.end());

            return intervals;
        }
};




#endif
