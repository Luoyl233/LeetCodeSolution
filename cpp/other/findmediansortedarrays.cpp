/*
 * 4. Median of Two Sorted Arrays
*/


#include "common.h"



#if LEET_CODE == 4


class Solution {
public:
    int findKth(vector<int> &a, int l1, vector<int> &b, int l2, int k) {
        int len1 = a.size() - l1;
        int len2 = b.size() - l2;

        if (len1 > len2) {
            return findKth(b, l2, a, l1, k);
        }
        if (len1 == 0) {
            return b[l2+k-1];
        }
        if (k == 1) {
            return a[l1] < b[l2] ? a[l1] : b[l2];
        }

        int h = k / 2;
        int mid1 = (h < len1 ? h : len1) - 1;
        int mid2 = (h < len2 ? h : len2) - 1;
        if (a[l1 + mid1] < b[l2 + mid2]) {
            return findKth(a, l1+mid1+1, b, l2, k-mid1-1);
        }
        else {
            return findKth(a, l1, b, l2+mid2+1, k-mid2-1);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;

        if (len % 2 == 0) {
            int l = len / 2;
            int r = r + 1;
            return (findKth(nums1, 0, nums2, 0, l) + findKth(nums1, 0, nums2, 0, r)) / 2.0;
        } else {
            int mid = len / 2 + 1;
            return findKth(nums1, 0, nums2, 0, mid);
        }
    }
};

int main()
{
    int a[] = {1};
    int b[] = {2,3,4,5,6};

    vector<int> nums1;
    vector<int> nums2;

    nums1.assign(a, a+1);
    nums2.assign(b, b+5);


    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

#endif
