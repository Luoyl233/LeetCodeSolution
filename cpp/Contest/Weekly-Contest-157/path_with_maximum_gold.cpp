/**
 * 1219. Path with Maximum Gold
 */

#include "common.h"

#if LEET_CODE == 1219

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i=0; i < grid.size(); i++) {
            for (int j=0; j < grid.front().size(); j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (0 <= i && i < grid.size() && 0 <= j && j < grid.front().size() && grid[i][j] > 0) {
            int gold = 0;
            grid[i][j] = -grid[i][j]; // mark as visited

            gold = max(gold, dfs(grid, i-1, j));
            gold = max(gold, dfs(grid, i+1, j));
            gold = max(gold, dfs(grid, i, j-1));
            gold = max(gold, dfs(grid, i, j+1));
            grid[i][j] = -grid[i][j];

            return gold + grid[i][j];
        } else
            return 0;
    }
};

#endif
