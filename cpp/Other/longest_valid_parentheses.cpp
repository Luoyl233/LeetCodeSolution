/*
 * 32. Longest Valid Parentheses
*/


#include "common.h"


#if LEET_CODE == 32

class Solution {
public:

    // O(n) solution Using a stack.
    int longestValidParentheses1(string s) {
        stack<int> st;
        int n = s.length();
        int res = 0;

        if (n == 0)
            return 0;

        for (int i=0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else if (!st.empty() && s[st.top()] == '(')
                st.pop();
            else
                st.push(i);
            }
        if (st.empty())
            res = n;
        else {
            int r = n-1, l;
            while (!st.empty()) {
                l = st.top(); st.pop();
                res = max(res, r-l);
                r = l-1;
            }
            // NOTE:
            res = max(res, l);
        }

        return res;
    }

    // O(n), DP solution.
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> longest(n+1, 0);
        int res = 0;

        for (int i=1; i < n; i++) {
             if (s[i] == ')') {
                 if (s[i-1] == '(')
                     longest[i] = 2 + (i-2 >= 0 ? longest[i-2] : 0);
                 else if (i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '(')
                     longest[i] = longest[i-1] + 2 + (i-longest[i-1]-2 >= 0 ? longest[i-longest[i-1]-2] : 0);
                 res = max(res, longest[i]);
             }
        }

        return res;
    }

};




#endif
