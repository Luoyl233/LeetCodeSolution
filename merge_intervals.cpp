/**
 * 56. Merge Intervals
 */

#include "common.h"

#if LEET_CODE == 56

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();

        if (n == 0)
            return res;

        sort(intervals.begin(), intervals.end(),    // Sort according to start time.
             [&](vector<int> &x, vector<int> &y) { return x[0] < y[0];});

        vector<int> curInterval = intervals[0];
        for (int i=1; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            if (interval[0] <= curInterval[1]) {
                // NOTE: interval[1] may less than curInterval[1] when interval[0] == curInterval[1].
                curInterval[1] = max(curInterval[1], interval[1]);
            } else {
                res.push_back(curInterval);
                curInterval = interval;
            }
        }
        res.push_back(curInterval);

        return res;
    }
};

#endif
