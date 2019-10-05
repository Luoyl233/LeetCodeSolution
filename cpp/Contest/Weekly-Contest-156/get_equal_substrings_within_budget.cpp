/*
 * 1208. Get Equal Substrings Within Budget
 */


#include "common.h"


#if LEET_CODE == 1208


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> costs(n);

        for (int i=0; i < n; i++)
            costs[i] = abs(s[i] - t[i]);

        int ans = 0;
        int curCost = 0;
        int left = 0, right = 0;

        while (right < n) {
            // Step right
            curCost += costs[right];

            // Slide left
            while (curCost > maxCost)
                curCost -= costs[left++];

            ans = max(ans, right-left+1);
            right ++;
        }

        return ans;
    }
};


#endif
