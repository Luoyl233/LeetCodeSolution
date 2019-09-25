/*
 * 238. Product of Array Except Self
 */


#include "common.h"


#if LEET_CODE == 238

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> products(n, 0);

        if (n == 0)
            return products;

        // L
        int p = 1;
        products[0] = p;
        for(int i=1; i < n; i++) {
            p *= nums[i-1];
            products[i] = p;
        }

        // R * L
        p = 1;
        products[n-1] *= p;
        for (int i=n-2; i >= 0; i--) {
            p *= nums[i+1];
            products[i] *= p;
        }

        return products;
    }
};

int main()
{
    cout << "238. Product of Array Except Self" << endl;

    return 0;
}


#endif
