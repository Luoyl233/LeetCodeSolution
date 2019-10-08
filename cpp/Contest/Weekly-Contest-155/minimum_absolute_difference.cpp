/**
 * 1200. Minimum Absolute Difference
 */

#include "common.h"

#if LEET_CODE == 1200

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int minDiff = 0x7fffffff;
        for (int i=1; i < n; i++)
            minDiff = min(minDiff, arr[i]-arr[i-1]);

        vector<vector<int>> ans;
        vector<int> tmp(2);

        for (int i=1; i < n; i++) {
            int diff = arr[i] - arr[i-1];
            if (diff == minDiff) {
                tmp[0] = arr[i-1];
                tmp[1] = arr[i];
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

#endif
