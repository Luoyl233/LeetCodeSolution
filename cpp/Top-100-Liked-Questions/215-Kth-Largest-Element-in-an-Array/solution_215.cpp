/*
 * 215. Kth Largest Element in an Array
 */

#include "common.h"

#if LEET_CODE == 215

class Solution {
public:
    // Minimum-Heap solution with time complexity O(NK) in all cases.
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

class Solution2 {
public:
    // Quick-Select has average O(N) time complexity,
    // but in worst case, it costs O(N^2) time (similar
    // to Quick-Sort, and we can optimize it by selecting
    // pivot).
    int findKthLargest(vector<int>& nums, int k) {
        return quickFind(nums, nums.size()-k, 0, nums.size()-1);
    }

    int quickFind(vector<int>& nums, int k, int left, int right) {
        int pivotIdx = partition(nums, left, right);
        if (k < pivotIdx) {
            return quickFind(nums, k, left, pivotIdx-1);
        } else if (k > pivotIdx) {
            return quickFind(nums, k, pivotIdx+1, right);
        } else {
            return nums[pivotIdx];
        }
    }

    // NOTE: There may be several differdent partition implements.
    // Be care of edge case, e.t.c. we use `nums[left] <= pivot)`
    // when scanning from left to right, while `nums[right] > pivot`
    // from right to left.
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left]; // TODO: Select a better pivot
        while (left < right) {
            while (right > left && nums[right] > pivot)
                right --;
            if (left < right)
                nums[left++] = nums[right];
            while (left < right && nums[left] <= pivot)
                left ++;
            if (left < right)
                nums[right--] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

int main()
{

    cout << "Find Kth Largest" << endl;
    return 0;
}

#endif
