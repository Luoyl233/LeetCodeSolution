/*
 * 1210. Minimum Moves to Reach Target with Rotations
 */


#include "common.h"


#if LEET_CODE == 1210


const int INI_VALUE = 0x7fffff00;

class Solution {
public:
    // TODO: Optimzie space from O(n^2) to O(n).
    // DP
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();

        // position (i, j) is where `tail` stays
        vector<vector<int>> H(n+1, vector<int>(n+1, INI_VALUE));
        vector<vector<int>> V(n+1, vector<int>(n+1, INI_VALUE));
        H[0][1] = -1; // start from (1, 1)

        // end at state H[n][n-1]
        for (int i=1; i <= n; i++) {
            for (int j=1; j <= n-1; j++) {
                if (!grid[i-1][j-1] && !grid[i-1][j])
                    H[i][j] = min(H[i-1][j], H[i][j-1]) + 1;
                if (!grid[i-1][j-1] && i < n && !grid[i][j-1])
                    V[i][j] = min(V[i-1][j], V[i][j-1]) + 1;
                if (!grid[i-1][j] && i < n && !grid[i][j])
                    H[i][j] = min(H[i][j], V[i][j]+1);
                if (i < n && !grid[i][j-1] && !grid[i][j])
                    V[i][j] = min(V[i][j], H[i][j]+1);
            }
        }

        return H[n][n-1] >= INI_VALUE ? -1 : H[n][n-1];
    }
};


#endif
