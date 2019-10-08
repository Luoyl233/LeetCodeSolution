/**
 * 69. Sqrt(x)
 */

#include "common.h"

#if LEET_CODE == 69

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;

        int left = 0, right = x / 2, pivot;
        long long square;
        while (left <= right) {
            pivot = (left + right) / 2;
            square = (long long)pivot * pivot;
            if (square < x)
                left = pivot + 1;
            else if (square > x)
                right = pivot - 1;
            else
                break;
        }
        return (left + right) / 2;
    }
};

#endif
