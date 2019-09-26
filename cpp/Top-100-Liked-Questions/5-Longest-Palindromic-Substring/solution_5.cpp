/*
 * 5. Longest Palindromic Substring
 */


#include "common.h"


#if LEET_CODE == 5

// TODO: Optimize
class Solution {
public:
    // DP
   string solution1(string s) {
        int len = s.size();
        if (len <= 1)
            return s;

        int start = 0;
        int n = -1;
        bool dp[len][len] = {false};

        for (int j=0; j < len; j++) {
            for (int i=j; i >= 0; i--) {
                if (s[i] == s[j] && (j-i <= 1 || dp[i+1][j-1] )) {
                    dp[i][j] = true;
                    if (j-i > n) {
                        n = j - i;
                        start = i;
                    }
                }
                else
                    dp[i][j] = false;
            }
        }

        return s.substr(start, n+1);
   }

    string longestPalindrome(string s) {

        return solution1(s);
    }
};


int main()
{
    cout << "5. Longest Palindromic Substring" << endl;

    return 0;
}


#endif
