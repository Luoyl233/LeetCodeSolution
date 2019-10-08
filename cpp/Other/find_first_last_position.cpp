/**
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */


#include "common.h"


#if LEET_CODE == 34

class Solution {
public:

    void binarySearch(vector<int> &nums, int low, int high, int target) {
        if (low <= high) {
            int mid = (low + high) / 2;
            if (target < nums[mid])
                binarySearch(nums, low, mid-1, target);
            else if(target > nums[mid])
                binarySearch(nums, mid+1, high, target);
            else {
                this->left = this->left >= 0 ? min(this->left, mid) : mid;
                this->right = max(this->right, mid);
                binarySearch(nums, low, mid-1, target);
                binarySearch(nums, mid+1, high, target);
            }
        }
    }

    // Inefficient solution.
    vector<int> searchRange1(vector<int>& nums, int target) {
        int n = nums.size();
        this->left = -1;
        this->right = -1;
        binarySearch(nums, 0, n-1, target);

        vector<int> res(2);
        res[0] = this->left;
        res[1] = this->right;

        return res;
    }

    // 2 times binary search.
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        if (n == 0) return res;

        int left = 0, right = n-1;

        while(left < right) {
            int mid = (left + right) / 2;
            if (target > nums[mid])
                left = mid + 1;
            else
                right = mid;
        }

        if (nums[right] != target)
            return res;

        res[0] = right;
        left = right;
        right = n-1;
        while (left < right) {
            // NOTE: biased to right, otherwise TLE.
            int mid = (left + right) / 2 + 1;
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid;
        }
        res[1] = left;

        return res;
    }


private:
    int left, right;
};




#endif
