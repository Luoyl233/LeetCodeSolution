/*
 * 53. Maximum Subarray
 */


#include "common.h"


#if LEET_CODE == 53

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = 0x80000000;
        for (int i=0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            sum = (sum > 0) ? sum : 0;
        }
        return maxSum;
    }
};

int main()
{
    cout << "53. Maximum Subarray" << endl;

    return 0;
}


#endif
