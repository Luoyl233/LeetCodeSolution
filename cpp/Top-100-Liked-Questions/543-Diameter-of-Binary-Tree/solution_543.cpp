/*
 * 543. Diameter of Binary Tree
 */


#include "common.h"


#if LEET_CODE == 543

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
    int diameter;

    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;

        computeDiameter(root);

        return diameter > 0 ? (diameter-1) : 0;
    }

    int computeDiameter(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftDepth = computeDiameter(root->left);
        int rightDepth = computeDiameter(root->right);
        diameter = max(diameter, 1+leftDepth+rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }
};

int main()
{
    cout << "543. Diameter of Binary Tree" << endl;

    return 0;
}


#endif
