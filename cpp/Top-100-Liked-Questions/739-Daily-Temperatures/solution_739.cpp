/*
 * 739. Daily Temperatures
 */

#include "common.h"

#if LEET_CODE == 739

class Solution {
public:
    // Stack
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);

        if (n == 0)
            return ans;

        stack<int> st;

        for (int i=0; i < n; i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int top = st.top(); st.pop();
                ans[top] = i - top;
            }
            st.push(i);
        }

        return ans;
    }
};

int main()
{

    cout << "739. Daily Temperatures" << endl;
    return 0;
}

#endif
