/*
 * 337. House Robber III
 */


#include "common.h"


#if LEET_CODE == 337

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res = search(root);

        return max(res.first, res.second);
    }

    pair<int, int> search(TreeNode* root) {
        // first: rob this; second: not rob this.
        pair<int, int> res = make_pair(0, 0);

        if (root == NULL)
            return res;

        pair<int, int> leftRes = search(root->left);
        pair<int, int> rightRes = search(root->right);

        res.first = root->val + leftRes.second + rightRes.second;
        res.second = max(leftRes.first, leftRes.second) + max(rightRes.first, rightRes.second);

        return res;
    }
};

int main()
{
    cout << "337. House Robber III" << endl;

    return 0;
}


#endif
