/**
 * 40. Combination Sum II
 */

#include "common.h"

#if LEET_CODE == 40

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;

        sort(candidates.begin(), candidates.end());
        findCombination(candidates, target, 0, res, combination);

        return res;
    }

    void findCombination(vector<int>& candidates, int target, int begin, vector<vector<int>> &res, vector<int> &combination) {
        if (target == 0) {
            res.push_back(combination);
        }
        else {
            // NOTE: ignore dupliocate nums.
            for (int i=begin; i < candidates.size() && candidates[i] <= target;) {
                combination.push_back(candidates[i]);
                findCombination(candidates, target-candidates[i], i+1, res, combination);
                combination.pop_back();

                i++;
                while (i < candidates.size() && candidates[i-1] == candidates[i]) {
                    i++;
                }
            }
        }
    }
};



#endif
