/*
 * 104. Maximum Depth of Binary Tree
 */


#include "common.h"


#if LEET_CODE == 104

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Level-order
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        if (root != NULL)
            q.push(root);
        while(!q.empty()) {
            ans ++;
            for (int i=q.size(); i > 0; i--) {
                TreeNode *p = q.front(); q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        return ans;
    }
};

// Postorder, recursively
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
    cout << "104. Maximum Depth of Binary Tree" << endl;

    return 0;
}


#endif
