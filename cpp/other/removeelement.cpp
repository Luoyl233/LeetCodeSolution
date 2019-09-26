/*
 * 27. Remove Element
*/

#include "common.h"


#if LEET_CODE == 27

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int step = 0;
        int remain = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                step ++;
            }
            else {
                nums[i-step] = nums[i];
            }
        }

        remain = n - step;

        nums.erase(nums.begin() + remain, nums.end());

        return remain;
    }
};

int main()
{
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> vec(8);
    vec.assign(arr, arr + 8);
    int val = 2;

    cout << Solution().removeElement(vec, val) << endl;
    for (vector<int>::iterator itr = vec.begin(); itr != vec.cend(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}

#endif
