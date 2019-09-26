/*
 * 10. Regular Expression Matching
 */


#include "common.h"


#if LEET_CODE == 10

// DP
class Solution {
public:
    // DP
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        for (int j=1; j <= n; j++) {
            char ch = p[j-1];
            bool star = (j < n && p[j] == '*');
            if (star) {
                dp[0][j] = dp[0][j+1] = dp[0][j-1];
            }

            for (int i=1; i <= m; i++) {
                if ((ch == '.' | ch == s[i-1])) {
                    if (star) {
                        dp[i][j+1] = dp[i][j] = dp[i-1][j] | dp[i-1][j-1];
                    } else {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
                if (star) {
                     dp[i][j+1] = dp[i][j] = dp[i][j] | dp[i][j-1];
                }
            }

            j += star;
        }

        return dp[m][n];
    }
};

// Recursively
class Solution2 {
public:
    // backtracking
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

    bool isMatch(string& s, int i, string& p, int j) {
        if (j == p.size() && i == s.size())
            return true;
        else if (j == p.size() && i != s.size())
            return false;

        bool flag = false;

        char ch = p[j];
        if (j+1 < p.size() && p[j+1] == '*') {
            int k = i;
            flag |= isMatch(s, k, p, j+2); // `*` do not match any charactor.
            while (!flag && k < s.size() && (ch == '.' || s[k] == ch)) {
                k ++;
                flag |= isMatch(s, k, p, j+2);
            }
        } else if (i < s.size() && (ch == '.' || s[i] == ch)) {
                flag = isMatch(s, i+1, p, j+1);
        }

        return flag;
    }
};

int main()
{
    cout << "10. Regular Expression Matching" << endl;

    return 0;
}


#endif
