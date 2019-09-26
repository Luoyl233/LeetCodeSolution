/**
 * 91. Decode Ways
 */

#include "common.h"


#if LEET_CODE == 91

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0');
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                int t = (s[i] -'0') * 10 + (s[i+1] - '0');
                dp[i] = dp[i+1] + ((t <= 26) ? dp[i+2] : 0);
            }
        }

        return dp[0];
    }
};

#endif
