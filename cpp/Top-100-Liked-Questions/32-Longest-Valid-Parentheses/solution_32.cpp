/*
 * 32. Longest Valid Parentheses
 */


#include "common.h"


#if LEET_CODE == 32

class Solution {
public:
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

int main()
{
    cout << "32. Longest Valid Parentheses" << endl;

    return 0;
}


#endif
