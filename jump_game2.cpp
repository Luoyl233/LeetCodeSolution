/**
 * 45. Jump Game II
 */


#include "common.h"

#if LEET_CODE == 45

class Solution {
public:
    int jump(vector<int>& nums) {
        return bfs(nums);
    }

    // TLE. Worest case: O(n^2).
    int dp(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0x7fffff);

        dp[n-1] = 0;
        for (int i=n-2; i >= 0; i--)
            for (int k=1; k <= nums[i] && (i+k) < n; k++)
                dp[i] = min(dp[i], dp[i+k]+1);

        return dp[0];
        }

    // BFS/greedy.
    int bfs(vector<int>& nums) {
        int n = nums.size();
        int curMax = 0, nextMax = 0;
        int jump = 0;

        // NOTE: i < n-1 !!!
        for (int i=0; i < n-1; i++) {
            nextMax = max(nextMax, i+nums[i]);
            if (i == curMax) {
                jump++;
                curMax = nextMax;
            }
        }

        return jump;
    }
};


#endif
