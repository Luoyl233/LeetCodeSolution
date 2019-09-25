/*
 * 438. Find All Anagrams in a String
 */


#include "common.h"


#if LEET_CODE == 438

class Solution {
public:
    // Fixed a window of size p.size().
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> required;
        int len = p.size();
        vector<int> ans;

        for (auto c : p) {
            required[c] ++;
        }

        int cnt = len;
        for (int i=0; i < s.size(); i++) {
            char ch = s[i];

            // exclude the char out of window
            if (i-len >= 0) {
                cnt += (required[s[i-len]] ++) >= 0 ;
            }

            // add current char to window
            required[ch] --;
            if (required[ch] >= 0)
                cnt --;

            // found anagram
            if (cnt == 0) {
                ans.push_back(i-len+1);
            }
        }

        return ans;
    }
};

int main()
{
    cout << "438. Find All Anagrams in a String" << endl;

    return 0;
}


#endif
