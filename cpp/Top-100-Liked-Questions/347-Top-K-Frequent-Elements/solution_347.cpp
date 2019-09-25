/*
 * 347. Top K Frequent Elements
 */


#include "common.h"


#if LEET_CODE == 347

struct Compare {
    public:
        bool operator() (pair<int, int>& pair1, pair<int, int> &pair2) {
            return pair1.second >= pair2.second;
        }
};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (auto num : nums) {
            mp[num] ++;
        }

        for (auto par : mp) {
            pq.push(par);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans(k);
        while (!pq.empty()) {
            auto par = pq.top(); pq.pop();
            ans[pq.size()] = par.first;
        }

        return ans;
    }
};

int main()
{
    cout << "347. Top K Frequent Elements" << endl;

    return 0;
}


#endif
