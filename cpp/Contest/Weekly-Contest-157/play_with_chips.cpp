/**
 * 1217. Play with Chips
 */

#include "common.h"

#if LEET_CODE == 1217

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int oddChips = 0;
        int evenChips = 0;

        for (auto pos : chips) {
            if (pos & 1)
                evenChips ++;
            else
                oddChips ++;
        }

        return min(evenChips, oddChips);
    }
};

#endif
