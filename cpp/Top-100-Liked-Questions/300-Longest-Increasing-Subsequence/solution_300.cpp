/*
 * 300. Longest Increasing Subsequence
 */


#include "common.h"


#if LEET_CODE == 300

class Solution {
public:
    // Optimal
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        int len = 0;
        for (auto num : nums) {
            auto iter = lower_bound(tails.begin(), tails.end(), num);
            if (iter == tails.end())
                tails.push_back(num);
            else
                *iter = num;
        }
        return tails.size();
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0)
            return 0;

        int longest = 0;
        vector<int> cnt(n, 1);

        for (int i=n-1; i >= 0; i--) {
            for (int j=i+1; j < n; j++) {
                if (nums[i] < nums[j])
                    cnt[i] = max(cnt[i], 1+cnt[j]);
            }
            longest = max(longest, cnt[i]);
        }

        return longest;
    }
};

int main()
{
    cout << "300. Longest Increasing Subsequence" << endl;

    return 0;
}


#endif
