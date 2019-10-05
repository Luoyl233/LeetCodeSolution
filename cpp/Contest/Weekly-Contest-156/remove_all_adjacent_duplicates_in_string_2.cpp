/*
 * 1209. Remove All Adjacent Duplicates in String II
 */


#include "common.h"


#if LEET_CODE == 1209


class Solution {
public:
    // Use stack
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; // pair(char, counts)
        int n = s.size();
        int len = n; // the final length of s
        int i = 0;

        while(i < n) {
            int j = i;
            while (j+1 < n && s[j+1] == s[j])
                j++;
            int cnt = j - i + 1;

            if (!st.empty() && st.top().first == s[i]) {
                cnt += st.top().second;
                st.pop();
            }

            len -= (cnt / k) * k;
            cnt = cnt % k; // letters that more than k is deleted
            if (cnt != 0)
                st.push(make_pair(s[i], cnt));

            i = j + 1;
        }

        string ans(len, ' ');
        while (!st.empty()) {
            pair<char, int> par = st.top(); st.pop();
            int f = par.second;
            while (f-- > 0)
                ans[--len] = par.first;
        }

        return ans;
    }
};


#endif
