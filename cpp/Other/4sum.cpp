/*
 * 18. 4Sum
*/

#include "common.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


#ifdef FOUR_SUM

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        int i, j, left, right;
        int sum;

        sort(nums.begin(), nums.end(), less<int>());

        for (i=0; i < n-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (j = n-1; j > i + 2; j--) {
                if (j < n-1 && nums[j] == nums[j+1]) continue;
                sum = target - nums[i] - nums[j];
                left = i+1;
                right = j-1;
                while (left < right) {
                    if (nums[left] + nums[right] < sum)
                        left ++;
                    else if (nums[left] + nums[right] > sum)
                        right --;
                    else {
                        vector<int> tuple4;
                        tuple4.push_back(nums[i]);
                        tuple4.push_back(nums[j]);
                        tuple4.push_back(nums[left]);
                        tuple4.push_back(nums[right]);
                        res.push_back(tuple4);

                        left ++; right --;
                        while (left < right && nums[left] == nums[left-1]) left ++;
                        while (left < right && nums[right] == nums[right+1]) right --;

                    }
                }
            }
        }

        return res;
    }
};


int main()
{
    int arr[] = {-3,-2,-1,0,0,1,2,3};
    vector<int> vec;
    int target = 0;
    vec.assign(arr, arr+8);

    vector<vector<int>> res = Solution().fourSum(vec, target);
    for (int i=0; i < res.size(); i++) {
        vector<int> vec = res[i];
        for_each(vec.begin(), vec.end(),
                 [](int x) {cout << x << " ";});
        cout << endl;
    }

    return 0;
}



#endif
