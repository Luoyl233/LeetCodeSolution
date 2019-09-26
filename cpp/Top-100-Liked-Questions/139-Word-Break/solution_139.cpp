/*
 * 139. Word Break
 */


#include "common.h"


#if LEET_CODE == 139

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        if (wordDict.size() == 0 && n > 0)
            return false;
        // vector to map
        unordered_map<string, bool> mp;
        int shortest, longest;
        shortest = longest = wordDict.front().length();
        for (auto str : wordDict) {
            mp[str] = true;
            shortest = min(shortest, (int)str.length());
            longest = max(longest, (int)str.length());
        }

        vector<bool> dp(n+1, false);
        dp[n] = true;

        for (int i=n-1; i-shortest+1 >= 0; i--) {
            if (dp[i+1] == false)
                continue;
            for (int len=shortest; len <= longest; len++) {
                int start = i+1-len;
                if (start < 0)
                    break;
                if (dp[start] == true)
                    continue;
                string substr = s.substr(start, len);
                // cout << substr << endl;
                dp[start] = mp.find(substr) != mp.end();
            }
        }

        return dp[0];
    }
};

int main()
{
    cout << "139. Word Break" << endl;

    return 0;
}


#endif
