/**
 * 55. Jump Game
 */

#include "common.h"

#if LEET_CODE == 55

class Solution {
public:
    // Greedy.
    bool canJump(vector<int>& nums) {
        int destination = nums.size();
        int farthest = 1; // The farthest step you can reach in range [0, curIdx].
        for (int curIdx=0; curIdx < farthest && farthest < destination; curIdx++) {
            farthest = max(farthest, (curIdx + nums[curIdx] + 1));
        }
        return farthest >= destination;
    }
};

#endif
