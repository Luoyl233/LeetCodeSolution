/*
 * 102. Binary Tree Level Order Traversal
 */


#include "common.h"


#if LEET_CODE == 102

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TODO: We can optimize level-order tranverse
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        vector<int> level;
        int curLevelCnt = 1, nextLevelCnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            if (curLevelCnt == 0) {
                ans.push_back(level);
                curLevelCnt = nextLevelCnt;
                nextLevelCnt = 0;
                level.clear();
            }
            TreeNode *p = q.front(); q.pop();
            curLevelCnt --;
            level.push_back(p->val);
            if (p->left) {
                q.push(p->left);
                nextLevelCnt ++;
            }
            if (p->right) {
                q.push(p->right);
                nextLevelCnt ++;
            }
        }
        if (!level.empty()) // Process the last level.
            ans.push_back(level);

        return ans;
    }
};

int main()
{
    cout << "102. Binary Tree Level Order Traversal" << endl;

    return 0;
}


#endif
