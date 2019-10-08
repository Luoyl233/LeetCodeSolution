/**
 * 1203. Sort Items by Groups Respecting Dependencies
 */

#include "common.h"

#if LEET_CODE == 1203

const int MAXN = 3e4 + 1;
int Q[MAXN];
list<int> V[MAXN];
int inDeg[MAXN];

void clear(int n) {
    for (int i=0; i < n; i++) {
        V[i].clear();
        inDeg[i] = 0;
    }
}

void addEdge(int from, int to) {
    V[from].push_back(to);
    inDeg[to] ++;
}

bool toposort(int n) {
    int head = 0;
    int tail = 0;

    for (int i=0; i < n; i++) {
        if (inDeg[i] == 0) {
            Q[tail++] = i;
        }
    }

    while (head < tail) {
        for (auto v : V[Q[head]]) {
            if (--inDeg[v] == 0)
                Q[tail++] = v;
        }
        head++;
    }

    return tail == n;
}

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> ans;

        // topo-sort items
        clear(n);

        for (int i=0; i < n; i++) {
            for (auto j : beforeItems[i])
                addEdge(j, i);
        }

        if (!toposort(n))
            return ans;

        // Topo-sort groups
        map<int, vector<int>> groupToItems;
        for (int i=0; i < n; i++) {
            if (group[Q[i]] == -1) {
                group[Q[i]] = m++;
            }
            groupToItems[group[Q[i]]].push_back(Q[i]);
        }

        clear(m);

        for (int i=0; i < n; i++) {
            for (auto j : beforeItems[i]) {
                if (group[i] != group[j])
                    addEdge(group[j], group[i]);
            }
        }

        if (!toposort(m))
            return ans;

        for (int i=0;i < m; i++) {
            for (auto item : groupToItems[Q[i]])
                ans.push_back(item);
        }

        return ans;
    }
};

#endif
