/*
 * 42. Trapping Rain Water
 */


#include "common.h"


#if LEET_CODE == 42

class Solution {
public:

   int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;

        int left = 0, right = height.size()-1;
        int res = 0;
        int maxLeft = height[left];
        int maxRight =  height[right];

        while (left < right) {
            if (height[left] < height[right]) {
                left ++;
                maxLeft = max(height[left], maxLeft);
                res += maxLeft - height[left];
            }
            else {
                right --;
                maxRight = max(maxRight, height[right]);
                res += maxRight - height[right];
            }
        }

        return res;
    }
};


int main()
{
    cout << "42. Trapping Rain Water" << endl;

    return 0;
}


#endif
