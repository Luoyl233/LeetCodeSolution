/*
 * 338. Counting Bits
 */


#include "common.h"


#if LEET_CODE == 338

class Solution {
public:
    vector<int> countBits(int num) {
        static vector<int> cnts = {0};

        while (cnts.size() <= num) {
            int i = cnts.size();
            cnts.push_back(cnts[i & (i-1)] + 1);
        }

        return vector<int>(cnts.begin(), cnts.begin()+num+1);
    }
};

int main()
{
    cout << "338. Counting Bits" << endl;

    return 0;
}


#endif
