/**
 * 1218. Longest Arithmetic Subsequence of Given Difference
 */

#include "common.h"

#if LEET_CODE == 1218

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (auto num : arr) {
            int pre = num - difference;
            int cnt = mp[pre] + 1;
            mp[num] = cnt;
            ans = max(ans, cnt);
        }

        return ans;
    }
};

#endif
