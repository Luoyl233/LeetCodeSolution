/*
 * 152. Maximum Product Subarray
 */


#include "common.h"


#if LEET_CODE == 152

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int minProduct = nums[0];
        int maxProduct = nums[0];
        int ans = nums[0];

        for (int i=1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(minProduct, maxProduct);

            minProduct = min(nums[i], nums[i] * minProduct);
            maxProduct = max(nums[i], nums[i] * maxProduct);

            ans = max(ans, maxProduct);
        }

        return ans;
    }
};

int main()
{
    cout << "152. Maximum Product Subarray" << endl;

    return 0;
}


#endif
