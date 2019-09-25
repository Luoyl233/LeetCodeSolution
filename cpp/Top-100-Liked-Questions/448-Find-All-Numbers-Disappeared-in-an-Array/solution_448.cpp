/*
 * 448. Find All Numbers Disappeared in an Array
 */


#include "common.h"


#if LEET_CODE == 448

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i=0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        for (int i=0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i+1);
        }

        return ans;
    }
};

int main()
{
    cout << "448. Find All Numbers Disappeared in an Array" << endl;

    return 0;
}


#endif
