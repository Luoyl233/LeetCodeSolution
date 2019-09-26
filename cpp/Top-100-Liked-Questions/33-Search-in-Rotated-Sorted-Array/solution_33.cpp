/*
 * 33. Search in Rotated Sorted Array
 */


#include "common.h"


#if LEET_CODE == 33

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;

        // The last element is the pivot.
        int pivot = nums.back();
        int left = 0;
        int right = n-1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            // Find it, return index directly.
            if (nums[mid] == target)
                return mid;

            // In this case, array is like this [..., MAX, MIN ...,  mid, ..., pivot].
            // The left side of mid is in range (pivot, MAX] U [MIN, mid),
            // and the right side is in range (mid, pivot].
            // the left and the right are disjoint.
            if (nums[mid] <= pivot) {
                // So if target is in range (mid, pivot], then it must be in the right side.
                if (nums[mid] < target && target <= pivot)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            // In this case, array is like this [..., mid, ...,  MAX, MIN , ..., pivot].
            // The left is in range (pivot, mid)/
            // The right is in range (mid, MAX] U [MIN, pivot]
            else {
                if (pivot < target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    cout << "33. Search in Rotated Sorted Array" << endl;

    return 0;
}


#endif
