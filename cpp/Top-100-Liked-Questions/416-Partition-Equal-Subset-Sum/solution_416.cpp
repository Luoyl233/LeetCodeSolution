/*
 * 416. Partition Equal Subset Sum
 */


#include "common.h"


#if LEET_CODE == 416

class Solution {
public:
    // Optimal solution using bitset
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1)
            return false;

        int target = sum >> 1;
        bitset<10001> bits(0);
        bits[0] = true;

        for (auto num : nums) {
            bits |= bits << num;
        }

        return bits[target];
    }
};

class Solution2 {
public:
    // DP
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums)
            sum += num;

        if (sum % 2 == 1) // odd
            return false;

        int n = nums.size();
        int target = sum / 2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for (int i=0; i < n; i++) {
            for (int j=target; j >= 0; j--) { // NOTE: j--
                if (j >= nums[i])
                    dp[j] = dp[j] | dp[j-nums[i]];
            }
        }

        return dp[target];
    }
};

int main()
{
    cout << "416. Partition Equal Subset Sum" << endl;

    return 0;
}


#endif
