/*
 * 16. 3Sum Closest
*/

#include "common.h"


#if LEET_CODE == 16


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];

        int n = nums.size();
        int mm = 0x7fffffff;
        int res;

        sort(nums.begin(), nums.end());

        for (int i=0; i < n-1; i++) {
            int left=i+1, right=n-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int t = abs(target-sum);
                if (t == 0)
                    return sum;
                if (t < mm) {
                    mm = t;
                    res = sum;
                }

                if (sum < target)
                    left ++;
                else
                    right --;
            }
        }

        return res;
    }
};


int main()
{
    int a[] = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    vector<int> nums;

    nums.assign(a, a+9);

    cout << Solution().threeSumClosest(nums, target) << endl;


    return 0;
}


#endif
