/*
 * 1. Two Sum
 */

#include "common.h"

#if LEET_CODE == 1

class Solution {
public:
    // One-pass Hash Table. O(n) time and space.
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans = {-1, -1};

        for (int i=0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                ans = {mp[complement], i};
                break;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};

class Solution2 {
public:
    // Brute-force. O(n^2) time, O(1) space.
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i < nums.size()-1; i++) {
            for(int j=i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{

    cout << "Two Sum" << endl;
    return 0;
}

#endif
