/*
 * 287. Find the Duplicate Number
 */


#include "common.h"


#if LEET_CODE == 287

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; // WHY ?
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int entry = 0;
        while (entry != slow) {
            entry = nums[entry];
            slow = nums[slow];
        }

        return entry;
    }
};

int main()
{
    cout << "287. Find the Duplicate Number" << endl;

    return 0;
}


#endif
