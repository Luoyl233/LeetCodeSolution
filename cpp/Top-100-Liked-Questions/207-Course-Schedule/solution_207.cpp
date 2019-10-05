/*
 * 207. Course Schedule
 */


#include "common.h"


#if LEET_CODE == 207

// Topo-sort
class Solution {
public:
    // topo structure
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<list<int>> V(numCourses);

        // Construct graph represented by adjacency-table
        for (auto e : prerequisites) {
            V[e[1]].push_back(e[0]);
            inDeg[e[0]] ++;
        }

        // Topo-sort
        queue<int> Q;
        for (int i=0; i < numCourses; i++) {
            if (inDeg[i] == 0)
                Q.push(i);
        }

        int cnt = Q.size();

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (auto v : V[u])
                if (--inDeg[v] == 0) {
                    Q.push(v);
                    cnt ++;
                }
        }

        return cnt == numCourses;
    }
};

// DFS
class Solution2 {
public:
    // DFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> V(numCourses);
        vector<bool> visited(numCourses, false);

        for (auto e : prerequisites) {
            V[e[1]].push_back(e[0]);
        }

        for (int i=0; i < numCourses; i++) {
            // Since we have resetted visited[i] when quiting dfs(i), we dont need to sweep array visted.
            if (!visited[i] && !dfs(V, visited, i))
                return false;
        }

        return true;
    }

    bool dfs(vector<list<int>>& V, vector<bool>& visited, int u) {
        if (visited[u])
            return false;

        visited[u] = true;

        for (auto v : V[u]) {
            if (!dfs(V, visited, v))
                return false;
        }

        // NOTE: Reset visited when quiting dfs
        visited[u] = false;

        return true;
    }
};

int main()
{
    cout << "207. Course Schedule" << endl;

    return 0;
}


#endif
