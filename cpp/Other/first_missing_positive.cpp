/**
 * 41. First Missing Positive
 */

#include "common.h"

#if LEET_CODE == 41

class Solution {
public:
    // O(n*logn) solution using sorting.
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 1;

        sort(nums.begin(), nums.end());

        int i = 1;
        int j = 0;
        for (int k = 0; k < n; k++) {
            if (nums[j] < i)
                j++;
            else if (nums[j] > i)
                break;
            else {
                i ++;
                j ++;
            }
        }

        return i;
    }

    // O(n) solution.
};

#endif
