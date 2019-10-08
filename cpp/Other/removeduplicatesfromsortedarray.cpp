/*
 * 26. Remove Duplicates from Sorted Array
*/

#include "common.h"


#if LEET_CODE == 26

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int remain = n;

        for (int i=1; i < n; i++) {
            if (nums[i] == nums[i-1])
                step ++;
            else
                nums[i-step] = nums[i];
        }

        remain = n - step;

        return remain;
    }
};


int main()
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> vec();
    vec.assign(arr, arr+10);

    int n = Solution().removeDuplicates(vec);

    cout << n << endl;
    for (int i=0; i < n; i++)
        cout << i << " ";
    cout << endl;

    return 0;
}

#endif
