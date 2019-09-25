/*
 * 169. Majority Element
 */


#include "common.h"


#if LEET_CODE == 169

// TODO: Optimize
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int freq = 0;
        int majority = 0;
        for (auto num : nums) {
            int cnt = mp[num];
            cnt ++;
            mp[num] = cnt;
            if (cnt > freq) {
                majority = num;
                freq = cnt;
            }
        }
        return majority;
    }
};

int main()
{
    cout << "169. Majority Element" << endl;

    return 0;
}


#endif
