/**
 * 1220. Count Vowels Permutation
 */

#include "common.h"

#if LEET_CODE == 1220

const long long MODULE = 1e9 + 7;

class Solution {
public:
    int countVowelPermutation(int n) {
        static vector<vector<int>> dp = {{1, 1, 1, 1, 1}};
        static vector<int> G[5] = {
            {1},
            {0, 2},
            {0, 1, 3, 4},
            {2,4},
            {0}
        };


        while (dp.size() < n) {
            int k = dp.size();
            dp.push_back(vector<int>(5, 0));
            for (int i=0; i < 5; i++) {
                for (int j : G[i])
                    dp[k][i] = (dp[k][i] + dp[k-1][j]) % MODULE;
            }
        }

        long long ans = 0;
        for (int i=0; i < 5; i++)
            ans += dp[n-1][i];

        return ans % MODULE;
    }
};

#endif
