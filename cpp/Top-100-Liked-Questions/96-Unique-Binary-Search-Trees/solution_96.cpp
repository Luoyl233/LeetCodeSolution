/*
 * 96. Unique Binary Search Trees
 */


#include "common.h"


#if LEET_CODE == 96

class Solution {
public:
    // Recursively
    int numTrees(int n) {
        if (n <= 1)
            return 1;

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i <= n; i++) {
            for (int j=0; j < i / 2; j++) {
                dp[i] += dp[j] * dp[i-1-j] * 2;
            }
            if (i % 2 == 1)
                dp[i] += dp[i/2] * dp[i/2];
        }

        return dp[n];
    }
};

int main()
{
    cout << "96. Unique Binary Search Trees" << endl;

    return 0;
}


#endif
