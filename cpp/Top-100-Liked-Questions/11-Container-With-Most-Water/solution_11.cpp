/*
 * 11. Container With Most Water
 */


#include "common.h"


#if LEET_CODE == 11

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxCapacity = 0;
        int left = 0;
        int right = n-1;

        while (left < right) {
            maxCapacity = max(maxCapacity,(right-left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left ++;
            else
                right --;
        }

        return maxCapacity;
    }
};

int main()
{
    cout << "11. Container With Most Water" << endl;

    return 0;
}


#endif
