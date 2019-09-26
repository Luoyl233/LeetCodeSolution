/*
 * 3. Longest Substring Without Repeating Characters
 */


#include "common.h"


#if LEET_CODE == 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
          return s.size();

        unordered_map<char, int> m;

        int i, j;
        int maxLen = 0;

        for (i=0, j=-1; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            } else {
                int k = m[s[i]];
                m[s[i]] = i;
                j = k > j ? k : j;
            }
            int curLen = i - j;
            maxLen = curLen > maxLen ? curLen : maxLen;
        }

        return maxLen;
    }
};

int main()
{
    cout << "3. Longest Substring Without Repeating Characters" << endl;

    return 0;
}


#endif
