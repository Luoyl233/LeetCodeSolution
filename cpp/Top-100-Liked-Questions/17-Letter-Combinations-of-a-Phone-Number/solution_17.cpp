/*
 * 17. Letter Combinations of a Phone Number
 */


#include "common.h"


#if LEET_CODE == 17

class Solution {
public:
    unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();

        if (n == 0)
            return ans;

        string s(n, ' ');

        combine(digits, 0, s, ans);

        return ans;
    }

    void combine(string& digits, int idx, string& s, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(s);
            return ;
        }

        string candidates = mp[digits[idx]];
        for (auto ch : candidates) {
            s[idx] = ch;
            combine(digits, idx+1, s, ans);
        }
    }
};

int main()
{
    cout << "17. Letter Combinations of a Phone Number" << endl;

    return 0;
}


#endif
