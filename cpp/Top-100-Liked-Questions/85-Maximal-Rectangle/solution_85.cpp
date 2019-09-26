/*
 * 85. Maximal Rectangle
 */


#include "common.h"


#if LEET_CODE == 85

// TODO: DP
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        return convertion(matrix);
    }

    int convertion(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.front().size();

        int maxArea = 0;
        vector<int> height(cols, 0);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j] ++;
                else
                    height[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleInHistogram(height));
        }

        return maxArea;
    }

    int largestRectangleInHistogram(vector<int>& heights) {
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
};

int main()
{
    cout << "85. Maximal Rectangle" << endl;

    return 0;
}


#endif
