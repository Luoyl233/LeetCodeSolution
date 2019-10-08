/**
 * 1202. Smallest String With Swaps
 */

#include "common.h"

#if LEET_CODE == 1202

class UnionFind {
public:
    UnionFind(int n) {
        this->size = n;
        this->elems = new int[n];
        for (int i=0; i < n; i++)
            elems[i] = -1;
    }

    ~UnionFind() {
        delete[] this->elems;
    }

    // find with path compress
    int find(int x) {
        int p = elems[x];
        if (p < 0)
            return x;
        else {
            int pp = find(p);
            elems[x] == pp;
            return pp;
        }
    }

    // weighted union
    void merge(int x, int y) {
        int r1 = find(x);
        int r2 = find(y);
        if (r1 != r2) {
            int w1 = elems[r1];
            int w2 = elems[r2];
            int w = w1 + w2;
            if (w1 < w2) {
                elems[r2] = r1;
                elems[r1] = w;
            } else {
                elems[r1] = r2;
                elems[r2] = w;
            }
        }
    }

private:
    int* elems;
    int size;
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        string ans = s;

        UnionFind uf(n);

        // union pairs
        for (auto par : pairs)
            uf.merge(par[0], par[1]);

        // transform union-find to sets
        unordered_map<int, vector<int>> sets;
        for (int i=0; i < n; i++) {
            int p = uf.find(i);
            if (sets.find(p) == sets.end())
                sets[p] = vector<int>();
            sets[p].push_back(i);
        }

        for (auto par : sets) {
            vector<int> &indices = par.second;

            sort(indices.begin(), indices.end());
            string substr(indices.size(), ' ');

            for (int i=0; i < indices.size(); i++) {
                substr[i] = s[indices[i]];
            }

            sort(substr.begin(), substr.end());

            for (int i=0; i < substr.size(); i++)
                ans[indices[i]] = substr[i];

        }

        return ans;
    }
};

#endif
