/**
 * 47. Permutations II
 */


#include "common.h"

#if LEET_CODE == 47

// Look later cause I still do not understand much.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0);
        return res;
    }

    // NOTE: Do NOT refer nums. WHY?
    void backtrack(vector<int> nums, vector<vector<int>>& res, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
        } else {
            for (int i=start; i < nums.size(); i++) {
                if (nums[start] != nums[i] || start == i) {
                    swap(nums[i], nums[start]);
                    backtrack(nums, res, start+1);
                    // Do not swap back. WHY?
                }
            }
        }
    }
};

#endif
