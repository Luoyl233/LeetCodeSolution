/**
 * 1232. Check If It Is a Straight Line
 */

#include "common.h"

#if LEET_CODE == 1232

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx0 = coordinates[1][0] - coordinates[0][0];
        int dy0 = coordinates[1][1] - coordinates[0][1];
        for (int i=2; i < coordinates.size(); i++) {
            int dx = coordinates[i][0] - coordinates[0][0];
            int dy = coordinates[i][1] - coordinates[0][1];
            if (dx * dy0 != dy * dx0)
                return false;
        }

        return true;
    }
};

#endif
