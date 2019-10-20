/**
 * 1234. Replace the Substring for Balanced String
 */

#include "common.h"

#if LEET_CODE == 1234

// Optimal
class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> count;
        int n = s.length(), res = n, i = 0;
        for (int j = 0; j < n; ++j) {
            count[s[j]]++;
        }
        for (int j = 0; j < n; ++j) {
            count[s[j]]--;
            while (i < n && count['Q'] <= n / 4 && count['W'] <= n / 4 && count['E'] <= n / 4 && count['R'] <= n / 4) {
                res = min(res, j - i + 1);
                count[s[i++]] += 1;
            }
        }
        return res;
    }
};

// My own
class Solution2 {
public:
    int balancedString(string s) {
        unordered_map<char, int> cnts;
        for (char c : s)
            cnts[c] ++;

        int ave = s.size() / 4;
        unordered_map<char, int> rq; // required chars in sliding window
        int n = 0;
        for (auto par : cnts) {
            if (par.second > ave) {
                rq[par.first] = par.second - ave;
                n += rq[par.first];
            }
        }

        if (n == 0)
            return 0;

        int ans = s.size();
        int cnt = 0;
        int j = 0;
        for (int i=0; i < s.size(); i++) {
            rq[s[i]] --;
            cnt += rq[s[i]] >= 0;

            while (cnt == n && j <= i) {
                ans = min(ans, i-j+1);
                rq[s[j]] ++;
                cnt -= rq[s[j++]] > 0;
            }
        }

        return ans;
    }
};


#endif
