/*
 * 70. Climbing Stairs
 */


#include "common.h"


#if LEET_CODE == 70

class Solution {
public:
    // Fabonacci sequence.
    int climbStairs(int n) {
        int pp = 1; // pre pre step
        int p = 1; // pre step
        for (int i=1; i < n; i++) {
            int cur = p + pp;
            pp = p;
            p = cur;
        }
        return p;
    }
};

int main()
{
    cout << "70. Climbing Stairs" << endl;

    return 0;
}


#endif
