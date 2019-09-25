/*
 * 279. Perfect Squares
 */


#include "common.h"


#if LEET_CODE == 279

class Solution {
public:
    // Static DP
    int numSquares(int n) {
        static vector<int> dp({0});

        while (dp.size() <= n) {
            int i = dp.size();
            int cnt = 0x7fffffff;
            for (int j=1; ; j++) {
                int square = j*j;
                if (square > i)
                    break;
                cnt = min(cnt, dp[i-square] + 1);
            }
            dp.push_back(cnt);
        }

        return dp[n];
    }
};

int main()
{
    cout << "279. Perfect Squares" << endl;

    return 0;
}


#endif
