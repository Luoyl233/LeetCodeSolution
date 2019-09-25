/*
 * 406. Queue Reconstruction by Height
 */


#include "common.h"


#if LEET_CODE == 406

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](vector<int>& p1, vector<int>& p2) {
                 if (p1[0] > p2[0])
                     return true;
                 else
                     return p1[0] == p2[0] && p1[1] <= p2[1];
        });

        vector<vector<int>> ans;
        for (auto p : people) {
            ans.insert(ans.begin()+p[1], p);
        }

        return ans;
    }
};

int main()
{
    cout << "406. Queue Reconstruction by Height" << endl;

    return 0;
}


#endif
