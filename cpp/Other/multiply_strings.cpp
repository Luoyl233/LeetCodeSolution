/**
 * 43. Multiply Strings
 */

#include "common.h"


#if LEET_CODE == 43

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        int digits[m + n] = {0};

        for (int i=m-1; i >= 0; i--) {
            for (int j=n-1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                digits[i+j+1] += mul;
                digits[i+j] += digits[i+j+1] / 10;
                digits[i+j+1] %= 10;
            }
        }

        string buffer;
        for (int i=0; i < m+n; i++) {
            if (digits[i] != 0 || buffer.length() > 0)
                buffer.push_back(digits[i] + '0');
        }
        if  (buffer.length() == 0) buffer.push_back('0');

        return buffer;
    }
};


#endif
