/*
 * 84. Largest Rectangle in Histogram
 */


#include "common.h"


#if LEET_CODE == 84

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            if (heights.empty())
                return 0;

            return stackMethod(heights);
        }

    // O(n) solution using stack.
    // curArea = curHeight * (right of lower than curHeight - left of lower than curHeight)
    int stackMethod(vector<int>& heights) {
        int n = heights.size();

        int maxArea = 0;
        stack<int> st;
        int i = 0;
        while (i < n || !st.empty()) {
            if (st.empty() || (i < n && heights[i] > heights[st.top()])) {
                st.push(i);
                i ++;
            } else {
                int h = heights[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, h * (i - left - 1));
            }
        }
        return maxArea;
    }

    // Time Limit Exceeded
    int bruteforce(vector<int>& heights) {
        int n = heights.size();

        int maxArea = 0;
        for (int i = 0; i < n; i ++) {
            int lowest = 0x7fffffffffffffff;
            for (int j = i; j < n; j ++) {
                lowest = min(lowest, heights[j]);
                maxArea = max(maxArea, (j+1-i) * lowest);
            }
        }
        return maxArea;
    }
};

#endif
