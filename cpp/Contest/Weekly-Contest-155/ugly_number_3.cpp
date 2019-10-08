/**
 * 1201. Ugly Number III
 */

#include "common.h"

#if LEET_CODE == 1201

// My implementation is too complex.
class Solution {
public:
    // binary search
    int nthUglyNumber(int n, int a, int b, int c) {
        sort3(a, b, c);

        long long left = 1;
        long long right = n * a;
        long long rank = -1;
        long long mid;
        while (true) {
            mid = (left + right) / 2;
            rank = computeRank(mid, a, b, c);

            // cout << mid << ", " << rank << endl;

            if (rank < n) {
                left = mid + 1;
            } else if (rank > n) {
                right = mid - 1;
            } else {
                break;
            }
        }

        while (!isUgly(mid, a, b, c)) {
            mid --;
        }

        return mid;
    }

    void sort3(int& a, int &b, int &c) {
        vector<int> nums(3);
        nums[0] = a;
        nums[1] = b;
        nums[2] = c;
        sort(nums.begin(), nums.end());
        a = nums[0];
        b = nums[1];
        c = nums[2];
    }

    int computeRank(long long k, long long a, long long b, long long c) {
        long long na = k / a;
        long long nb = k / b;
        long long nc = k / c;

        long long nab = commonFactor(k, a, b);
        long long nac = commonFactor(k, a, c);
        long long nbc = commonFactor(k, b, c);

        long long nabc = commonFactor3(k, a, b, c);

        return (na + nb + nc - nab - nac - nbc + nabc);
    }

    bool isUgly(int num, int a, int b, int c) {
        return (num % a == 0) | (num % b == 0) | (num % c == 0);
    }

    int gcd(int x, int y) {
        if (x == 0)
            return y;
        else
            return gcd(y % x, x);
    }

    long long commonFactor(long long k, long long a, long long b) {
        if (a == b) {
            return k / a;
        } else
            return (k * gcd(a, b) / a) / b;
    }

    long long commonFactor3(long long k, long long a, long long b, long long c) {
        int ab = gcd(a, b);
        int ac = gcd(a, c);
        int bc = gcd(b, c);

        int abc;
        if (ab < c)
            abc = gcd(ab, c);
        else
            abc = gcd(c, ab);

        return k * ab * ac * bc / a / b / c / abc;
    }
};

// Here is code of others.
class Solution {
public:
   int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k)
                lo = mid + 1;
            else
               //the condition: F(N) >= k
                hi = mid;
        }
        return lo;
    }
};


#endif
