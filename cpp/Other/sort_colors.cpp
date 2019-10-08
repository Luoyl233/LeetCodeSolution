/**
 * 75. Sort Colors
 */

#include "common.h"

#if LEET_CODE == 75

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1)
            return;

        int left = 0;
        int right = nums.size() - 1;
        int curIdx = 0; // Scan from left to right.

        while (curIdx <= right) {
            if (nums[curIdx] == 0) {
                if (left < curIdx)
                    swap(nums[left], nums[curIdx]);
                curIdx ++;
                left ++;
            }
            else if (nums[curIdx] == 2) {
                swap(nums[curIdx], nums[right]);
                right --;
            }
            else
                curIdx ++;
        }
    }
};

#endif
