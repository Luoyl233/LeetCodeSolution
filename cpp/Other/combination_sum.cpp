/**
 * 39. Combination Sum
 */


#include "common.h"


#if LEET_CODE == 39

class Solution {
public:
    // Brute-force solution.
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;

        sort(candidates.begin(), candidates.end());
        findCombination(candidates, target, 0, res, combination);

        return res;
    }

    void findCombination(vector<int> &candidates, int target, int begin, vector<vector<int>> &res, vector<int> &combination) {
        if (target == 0) {
            res.push_back(combination);
        }
        else {
            int n = candidates.size();
            for (int i=begin; i < n && candidates[i] <= target; i++) {
                combination.push_back(candidates[i]);
                findCombination(candidates, target-candidates[i], i, res, combination);
                combination.pop_back();
            }
        }
    }
};


#endif
