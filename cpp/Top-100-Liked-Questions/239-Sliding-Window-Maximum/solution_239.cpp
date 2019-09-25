/*
 * 239. Sliding Window Maximum
 */

#include "common.h"

#if LEET_CODE == 239

class Solution {
public:
    // Optimal solution using double-ended-queue.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return vector<int>();

        deque<int> q;
        vector<int> ans;

        for (int i=0; i < n; i++) {
            if (!q.empty() && q.front() < i-k+1)
                q.pop_front();
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);

            if (i >= k-1)
                ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};

class Solution2 {
public:
    // My first solution with O(NK) time complexity in worst case.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0)
            return vector<int>();

        vector<int> ans(n-k+1, 0);
        int maxIdx = findMaxInWindow(nums, k, 0);
        ans[0] = nums[maxIdx];
        for (int i=1; i < n-k+1; i++) {
            if (maxIdx < i) {
                maxIdx = findMaxInWindow(nums, k, i);
            } else {
                maxIdx = (nums[i+k-1] >= nums[maxIdx]) ? (i+k-1) : maxIdx;
            }
            ans[i] = nums[maxIdx];
        }

        return ans;
    }

    int findMaxInWindow(vector<int>& nums, int k, int start) {
        int idx = start;
        for (int i=1; i < k; i++)
            idx = (nums[start+i] > nums[idx]) ? (start+i) : idx;
        return idx;
    }
};

int main()
{

    cout << "Sliding Window Maximum" << endl;
    return 0;
}

#endif
