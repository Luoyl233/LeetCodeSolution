/*
 *9. Palindrome Number
*/

#include "common.h"


#if LEET_CODE == 9


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else if (0 <= x && x < 10)
            return true;

        char str[16];
        int n = sprintf(str, "%d", x);

        for (int i=0, j=n-1; i <= j; i ++, j--)
            if (str[i] != str[j])
                return false;

        return true;
    }
};


int main()
{
    int x = 1000000001;

    cout << Solution().isPalindrome(x) << endl;

    return 0;
}

#endif
