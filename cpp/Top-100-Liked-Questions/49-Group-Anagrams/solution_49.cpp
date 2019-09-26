/*
 * 49. Group Anagrams
 */


#include "common.h"


#if LEET_CODE == 49

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (int i=0; i < strs.size(); i++) {
            string orderedStr = strs[i];
            sort(orderedStr.begin(), orderedStr.end());
            mp[orderedStr].push_back(strs[i]);
        }

        unordered_map<string, vector<string>>::iterator iter;
        for (iter=mp.begin(); iter != mp.end(); iter++) {
            res.push_back((*iter).second);
        }

        return res;
    }
};

int main()
{
    cout << "49. Group Anagrams" << endl;

    return 0;
}


#endif
