/**
 * 53. Maximum Subarray
 */

#include "common.h"

#if LEET_CODE == 53


class Solution {
public:
    // O(n) solution.
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0x80000000;
        for (int i=0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            sum = max(sum, 0);
        }
        return maxSum;
    }

    // What about divide and conquer approach?
};


#endif
