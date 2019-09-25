/*
 * 283. Move Zeroes
 */


#include "common.h"


#if LEET_CODE == 283

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt ++;
            }
            else if (cnt > 0) {
                nums[i - cnt] = nums[i];
                nums[i] = 0;
            }
        }
    }
};

int main()
{
    cout << "283. Move Zeroes" << endl;

    return 0;
}


#endif
