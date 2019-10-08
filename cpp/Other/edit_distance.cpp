/**
 * 72. Edit Distance
 */

#include "common.h"

#if LEET_CODE == 72

class Solution {
public:
        int minDistance(string word1, string word2) {
                int m = word1.size();
                int n = word2.size();
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

                // Init the first row.
                for (int i = 1; i <= m; i++)
                        dp[i][0] = i;

                // Init thr first column.
                for (int j = 1; j <= n; j++)
                        dp[0][j] = j;

                for (int i = 1; i <= m; i++) {
                        for (int j = 1; j <= n; j++) {
                                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1; // min(insert, delete)
                                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (word1[i-1] != word2[j-1])); // min(dp[i][j], replace)
                        }
                }

                return dp[m][n];
        }
};

#endif
