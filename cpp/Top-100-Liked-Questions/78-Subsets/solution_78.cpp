/*
 * 78. Subsets
 */


#include "common.h"


#if LEET_CODE == 78

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curSet;

        ans.push_back(curSet);
        genSubsets(nums, 0, curSet, ans);

        return ans;
    }

    void genSubsets(vector<int> &nums, int curIdx, vector<int> &curSet, vector<vector<int>>& ans) {
        if (curIdx < nums.size()) {
            curSet.push_back(nums[curIdx]);
            ans.push_back(curSet);
            genSubsets(nums, curIdx+1, curSet, ans);
            curSet.pop_back();

            genSubsets(nums, curIdx+1, curSet, ans);
        }
    }
};

int main()
{
    cout << "78. Subsets" << endl;

    return 0;
}


#endif
