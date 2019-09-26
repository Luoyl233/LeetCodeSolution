/**
 * 22. Generate Parentheses
 */

#include "common.h"

#if LEET_CODE == 22


// TODO: Complexity analysis.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        string s(n*2, ' ');

        genParenthesisRecursively(n, 0, 0, res, s);

        return res;
    }

    void genParenthesisRecursively(int n, int stIdx, int curIdx, vector<string> &res, string &s) {
        if (n == 0 && stIdx == 0) {
            res.push_back(s);
            return;
        }
        if (n > 0) { // insert '(' when push
            s[curIdx] = '(';
            genParenthesisRecursively(n-1, stIdx+1, curIdx+1, res, s);
        }
        if (stIdx > 0) { // insert ')' when pop
            s[curIdx] = ')';
            genParenthesisRecursively(n, stIdx-1, curIdx+1, res, s);
        }
    }
};

#endif
