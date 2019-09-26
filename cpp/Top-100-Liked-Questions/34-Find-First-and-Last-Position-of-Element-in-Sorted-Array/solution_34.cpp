/*
 * 34. Find First and Last Position of Element in Sorted Array
 */


#include "common.h"


#if LEET_CODE == 34

class Solution {
public:
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
            int mid = (left + right) / 2  + 1;
            if (target < nums[mid])
                right = mid-1;
            else
                left = mid;
        }
        res[1] = left;

        return res;
    }
};

int main()
{
    cout << "34. Find First and Last Position of Element in Sorted Array" << endl;

    return 0;
}


#endif
