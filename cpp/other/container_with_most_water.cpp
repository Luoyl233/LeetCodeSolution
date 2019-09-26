/*
 * 11. Container With Most Water
*/

#include "common.h"

#if LEET_CODE == 11


class Solution {
public:

    // RE: Stack overflow
    int maxArea1(vector<int>& height) {
        int n = height.size();
        int dp[n][n] = {0};

        for (int j=0; j < n; j++)
            for (int i=j; i >= 0; i--) {
                int capacity = (j-i) * min(height[i], height[j]);
                if (i < n-1)
                    capacity = max(capacity, dp[i+1][j]);
                if (j > 0)
                    capacity = max(capacity, dp[i][j-1]);
                if (i < n-1 && j > 0)
                    capacity = max(capacity, dp[i+1][j-1]);
                dp[i][j] = capacity;
            }

        return dp[0][n-1];
    }

    // Brute-force
    int maxArea2(vector<int>& height) {
        int n = height.size();
        int maxCapacity = 0;

        for (int j=0; j < n; j++)
            for (int i=j; i >= 0; i--) {
                int capacity = (j-i) * min(height[i], height[j]);
                maxCapacity = max(maxCapacity, capacity);
            }

        return maxCapacity;
    }

    // Best solution. But how to explain ?
    // Double pointer.
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
    int h[] = {1,8,6,2,5,4,8,3,7};
    vector<int> height;

    height.assign(h, h+9);

    cout << Solution().maxArea(height) << endl;

    return 0;
}


#endif
