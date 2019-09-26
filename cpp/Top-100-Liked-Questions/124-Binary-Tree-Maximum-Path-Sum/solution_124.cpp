/*
 * 124. Binary Tree Maximum Path Sum
 */


#include "common.h"


#if LEET_CODE == 124

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
    // TOOD: Optimize
    int maxPathSum(TreeNode* root) {
        int maxValue = 0x80000000;
        findMaxPathSum(root, maxValue);
        return maxValue;
    }

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int findMaxPathSum(TreeNode *root, int& maxValue) {
        if (root == nullptr) return 0;
        int left = max(0, findMaxPathSum(root->left, maxValue));
        int right = max(0, findMaxPathSum(root->right, maxValue));
        if (maxValue < (left + root->val + right))
            maxValue = (left + root->val + right);
        return max(left + root->val, right + root->val);
    }
};

int main()
{
    cout << "124. Binary Tree Maximum Path Sum" << endl;

    return 0;
}


#endif
