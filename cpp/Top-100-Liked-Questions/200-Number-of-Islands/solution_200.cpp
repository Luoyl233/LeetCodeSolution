/*
 * 200. Number of Islands
 */


#include "common.h"


#if LEET_CODE == 200

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numComponents = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (grid[i][j] == '1') { // not visited island
                    numComponents ++;
                    visitIsland(i, j, grid);
                }
            }
        }
        return numComponents;
    }

    void visitIsland(int i, int j, vector<vector<char>>& grid) {
        if (0 <= i && i < grid.size() && 0 <= j && j < grid.front().size() && grid[i][j] == '1') {
            grid[i][j] = '2'; // mark as visited
            visitIsland(i-1, j, grid);
            visitIsland(i+1, j, grid);
            visitIsland(i, j-1, grid);
            visitIsland(i, j+1, grid);
        }
    }
};

int main()
{
    cout << "200. Number of Islands" << endl;

    return 0;
}


#endif
