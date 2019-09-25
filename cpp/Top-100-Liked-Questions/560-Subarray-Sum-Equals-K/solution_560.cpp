/*
 * 560. Subarray Sum Equals K
 */


#include "common.h"


#if LEET_CODE == 560

class Solution {
public:
    // Hashmap
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        mp[0] = 1; // NOTE
        for (auto num : nums) {
            sum += num;
            if (mp.find(sum-k) != mp.end()) {
                ans += mp[sum-k];
            }
            mp[sum] ++;
        }

        return ans;
    }
};

int main()
{
    cout << "560. Subarray Sum Equals K" << endl;

    return 0;
}


#endif
