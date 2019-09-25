/*
 * 322. Coin Change
 */


#include "common.h"


#if LEET_CODE == 322

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0x7ffffffe); // Note: in case of overflow
        dp[0] = 0;

        for (auto coin : coins) {
            for (int i=1; i <= amount; i++) {
                if (coin <= i)
                    dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }

        return dp[amount] == 0x7ffffffe ? -1 : dp[amount];
    }
};

int main()
{
    cout << "322. Coin Change" << endl;

    return 0;
}


#endif
