/*
 * 198. House Robber
 */


#include "common.h"


#if LEET_CODE == 198

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int maxMoney = 0;

        for (int i=0; i < n; i++) {
            dp[i] = (i-3 >= 0) ? max(dp[i], dp[i-3]+nums[i]) : nums[i];
            dp[i] = (i-2 >= 0) ? max(dp[i], dp[i-2]+nums[i]) : nums[i];
            maxMoney = max(maxMoney, dp[i]);
        }

        return maxMoney;
    }
};

int main()
{
    cout << "198. House Robber" << endl;

    return 0;
}


#endif
