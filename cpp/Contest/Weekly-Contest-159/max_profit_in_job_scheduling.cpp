/**
 * 1235. Maximum Profit in Job Scheduling
 */

#include "common.h"

#if LEET_CODE == 1235

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<vector<int>> jobs(n);
        for (int i=0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end(), [](vector<int>& x, vector<int>& y) { return x[1] < y[1]; });

        vector<int> dp(n);
        vector<int> ends;

        for (int i=0; i < n; i++) {
            int k = distance(ends.begin(), lower_bound(ends.begin(), ends.begin()+i, jobs[i][0]+1)) - 1;

            dp[i] = (i > 0) ? dp[i-1] : 0;
            int preMax = (k >= 0 && jobs[k][1] <= jobs[i][0]) ? dp[k] : 0;
            dp[i] = max(dp[i], preMax + jobs[i][2]);
            ends.push_back(jobs[i][1]);
        }

        return dp[n-1];
    }
};

#endif
