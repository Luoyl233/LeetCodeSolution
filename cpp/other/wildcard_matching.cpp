/**
 * 44. Wildcard Matching
 */

#include "common.h"

#if LEET_CODE == 44

class Solution {
public:
    // Double pointer solution. Not done yet.
    bool isMatch1(string s, string p) {
        int i = 0, j = 0;
        int star = 0;
        int pos = -1;

        while (i < s.length()) {
            if (s[i] == p[j]) {
                i++; j++;
                // Try match.
                if (star == 1) {
                    star = 2;
                    pos = i;
                }
            }
            else if(p[j] == '?') {
                i++; j++;
            }
            else if (p[j] == '*') {
                star = 1;
            }

            if (star == 1) {
                s ++;
            }

            if (i == s.length() && j < p.length() && star != 0) {
                i = pos;
            }
        }

        return i == j;
    }

    // DP.
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));

        dp[0][0] = true;
        for (int i=1; i <= s.size(); i++) {
            dp[i][0] = false;
        }

        for (int j=1; j <= p.size(); j++) {
            dp[0][j] = (dp[0][j-1] && p[j-1] == '*');
        }

        for (int i=1; i <= s.size(); i++) {
            for (int j=1; j <= p.size(); j++) {
                if ((s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1])
                    dp[i][j] = true;
                else if (p[j-1] == '*' && (dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1]))
                    dp[i][j] = true;
            }
        }

        return dp[s.size()][p.size()];
    }

};



#endif
