/*
 * 128. Longest Consecutive Sequence
 */


#include "common.h"


#if LEET_CODE == 128

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;
        for (auto num : nums)
            S.insert(num);

        int longest = 0;

        for (auto num : nums) {
            if (S.find(num-1) != S.end())
                continue;

            int cnt = 1;
            while (S.find(num+1) != S.end()) {
                num ++;
                cnt ++;
            }

            longest = max(longest, cnt);
        }

        return longest;
    }
};

int main()
{
    cout << "128. Longest Consecutive Sequence" << endl;

    return 0;
}


#endif
