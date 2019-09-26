/*
 * 136. Single Number
 */


#include "common.h"


#if LEET_CODE == 136

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // xor
        int ans = 0;
        for (int i=0; i < nums.size(); i++)
            ans ^= nums[i];
        return ans;
    }
};

int main()
{
    cout << "136. Single Number" << endl;

    return 0;
}


#endif
