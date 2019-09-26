/*
 * 62. Unique Paths
 */


#include "common.h"


#if LEET_CODE == 62

long long dp[100][100] = {0};
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 1;

        dp[0][0] = 1;

        for (int i = 0; i < m; i ++)
            dp[i][0] = 1;

        for (int j = 0; j < n; j ++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i ++)
            for (int j = 1;j < n; j ++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

        return dp[m-1][n-1];
    }
};

int main()
{
    cout << "62. Unique Paths" << endl;

    return 0;
}


#endif
