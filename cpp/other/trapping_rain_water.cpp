/**
 * 42. Trapping Rain Water
 */

#include "common.h"

#if LEET_CODE == 42

class Solution {
public:
    // My own O(3n) time, O(2n) space solution.
    int trap1(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> leftHeight(n, 0);
        vector<int> rightHeight(n, 0);

        // Travel from left to right.
        for (int i=0; i < n; i++) {
            leftHeight[i] = (i-1 >= 0) ? max(leftHeight[i-1], height[i]) : height[i];
        }

        // Travel from right to left.
        for (int i=n-1; i >= 0; i--) {
            rightHeight[i] = (i+1 < n) ? max(rightHeight[i+1], height[i]) : height[i];
        }

        for (int i=0; i < n; i++)
            res += min(leftHeight[i], rightHeight[i]) - height[i];

        return res;
    }

    // O(n) time, O(1) space solution.
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


#endif
