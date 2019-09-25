/*
 * 312. Burst Balloons
 */


#include "common.h"


#if LEET_CODE == 312

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        for (int k=2; k <= n+1; k++) {
            for (int start=0; start+k <= n+1; start++) {
                int end = start + k;
                int coins = nums[start] * nums[end];
                for (int j=start+1; j < end; j++) {
                    dp[start][end] = max(dp[start][end], dp[start][j] + coins*nums[j] + dp[j][end]);
                }
            }
        }

        return dp[0][n+1];
    }
};

int main()
{
    cout << "312. Burst Balloons" << endl;

    return 0;
}


#endif
