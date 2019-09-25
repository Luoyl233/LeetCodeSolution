/*
 * 437. Path Sum III
 */


#include "common.h"


#if LEET_CODE == 437

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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        else
            return findPath(root, sum, 0, true);
    }

    int findPath(TreeNode* parent, int target, int sum, bool startFromParent) {
        if (parent == NULL)
            return 0;

        int cnt = 0;

        if (startFromParent) {
            sum = parent->val;
            cnt += findPath(parent->left, target, parent->val, true) + findPath(parent->right, target, parent->val, true);
        } else {
            sum += parent->val;
        }

        cnt += (sum == target);
        cnt += findPath(parent->left, target, sum, false) + findPath(parent->right, target, sum, false);

        return cnt;
    }
};

int main()
{
    cout << "437. Path Sum III" << endl;

    return 0;
}


#endif
