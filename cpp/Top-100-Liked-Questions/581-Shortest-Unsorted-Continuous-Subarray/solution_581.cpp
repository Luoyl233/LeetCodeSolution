/*
 * 581. Shortest Unsorted Continuous Subarray
 */


#include "common.h"


#if LEET_CODE == 581

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left, right; // left is the start index of unsorted subarray. Right is the  index of  rightordered subarray. So length is (right - left), without add 1;

        // Scan from left to right, finding left border
        for (left=0; left < n-1 && nums[left] <= nums[left+1]; left++);

        int minValue = nums[left];
        for (int i=left+1; i < n; i++) {
            minValue = min(minValue, nums[i]);
        }
        left = upper_bound(nums.begin(), nums.begin()+left, minValue) - nums.begin();

        for (right=n-1; right > 0 && nums[right] >= nums[right-1]; right--);

        int maxValue = nums[right];
        for (int i=right-1; i >= 0; i--) {
            maxValue = max(maxValue, nums[i]);
        }
        right = lower_bound(nums.begin()+right, nums.end(), maxValue) - nums.begin();

        return right > left ? (right-left) : 0;
    }
};

int main()
{
    cout << "581. Shortest Unsorted Continuous Subarray" << endl;

    return 0;
}


#endif
