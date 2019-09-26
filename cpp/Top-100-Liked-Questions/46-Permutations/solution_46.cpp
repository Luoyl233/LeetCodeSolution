/*
 * 46. Permutations
 */


#include "common.h"


#if LEET_CODE == 46

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>> &res, int curIndex) {
        int n = nums.size();
        if (curIndex == n) {
            res.push_back(nums);
        } else {
            for (int i=0; i <= curIndex; i++) {
            swap(nums[i], nums[curIndex]);
            backtrack(nums, res, curIndex+1);
            swap(nums[i], nums[curIndex]);
            }
        }
    }
};

int main()
{
    cout << "46. Permutations" << endl;

    return 0;
}


#endif
