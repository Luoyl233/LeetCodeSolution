/**
 * 47. Permutations II
 */


#include "common.h"

#if LEET_CODE == 47

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
//        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, int begin) {
        if (begin == nums.size()) {
            res.push_back(nums);
        } else {
            for (int i=0; i <= begin; i++) {
                if (i == begin || nums[i] != nums[begin]) {
                    swap(nums[i], nums[begin]);
                    backtrack(nums, res, begin+1);
                    swap(nums[i], nums[begin]);
                }
            }
        }
    }
};

#endif
