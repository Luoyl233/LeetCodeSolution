/*
 * 1207. Unique Number of Occurrences
 */


#include "common.h"


#if LEET_CODE == 1207


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> M;
        for (auto x : arr)
            M[x] ++;

        unordered_set<int> S;

        for (auto par : M) {
            if (S.find(par.second) != S.end())
                return false;
            S.insert(par.second);
        }

        return true;
    }
};


#endif
