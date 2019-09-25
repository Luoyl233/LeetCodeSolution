/*
 * 494. Target Sum
 */


#include "common.h"


#if LEET_CODE == 494

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((sum & 1) != (S & 1) || abs(S) > sum)
            return 0;

        // Transform to subset sum problem
        int target = (sum + S) / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (auto num : nums) {
            for (int j=target; j >= 0; j--) {
                if (j-num >= 0)
                    dp[j] += dp[j-num];
            }
        }

        return dp[target];
    }
};

int main()
{
    cout << "494. Target Sum" << endl;

    return 0;
}


#endif
