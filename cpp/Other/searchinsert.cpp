/*
 * 35. Search Insert Position
*/


#include "common.h"


#if LEET_CODE == 35

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        int idx = 0;

        if (n == 0 || nums[0] > target)
            return 0;
        if (nums[right] < target)
            return n;

        while (left <= right) {
            idx = (left + right) / 2;
            if (nums[idx] < target) {
                left = idx + 1;
            }
            else if (nums[idx] > target) {
                right = idx - 1;
            }
            else {
                return idx;
            }
        }

        return left;
    }
};

int main()
{
    int a[] = {1, 3, 5, 6};
    vector<int> nums(4);
    nums.assign(a, a + 4);
    int target = 7;

    cout << Solution().searchInsert(nums, target) << endl;

    return 0;
}

#endif
