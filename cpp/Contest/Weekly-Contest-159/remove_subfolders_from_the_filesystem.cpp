/**
 * 1233. Remove Sub-Folders from the Filesystem
 */

#include "common.h"

#if LEET_CODE == 1233

// Optimal
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& A) {
        vector < string > ans;
        sort(A.begin(), A.end());
        int n = A.size();
        string cur = A[0];
        for(int i = 1;i < n;++i) {
            if(A[i].find(cur) != string::npos) {
                continue;
            }
            cur = A[i];
            ans.push_back(cur);
        }
        ans.push_back(A[0]);
        return ans;
    }
};

// My own
struct TrieNode {
    unordered_map<string, TrieNode*> mp;
    bool isFolder;
    TrieNode(): isFolder(false) {}
};

class Solution2 {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode *root = new TrieNode();
        for (auto f : folder) {
            TrieNode* cur = root;
            int i = 1;
            int j = 1;
            while (i < f.size()) {
                int j = f.find('/', i);
                string ss = f.substr(i-1, j-i+1);
                if (j != -1)
                    i = j + 1;
                else
                    i = f.size();

                if (cur->mp.find(ss) == cur->mp.end()) {
                    cur->mp[ss] = new TrieNode();
                }
                if (cur->isFolder) {
                    break;
                }
                cur = cur->mp[ss];
            }
            cur->isFolder = true;
            // delete childs
        }

        vector<string> ans;
        genFolder(root, "", ans);

        return ans;
    }

    void genFolder(TrieNode* r, string path,vector<string>& ans) {
        for (auto par : r->mp) {
            if (par.second->isFolder == true) {
                ans.push_back(path + par.first);
            } else {
                genFolder(par.second, path + par.first, ans);
            }
        }
    }
};

#endif
