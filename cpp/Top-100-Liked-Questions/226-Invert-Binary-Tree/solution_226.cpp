/*
 * 226. Invert Binary Tree
 */


#include "common.h"


#if LEET_CODE == 226

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode* lChild = invertTree(root->left);
        TreeNode* rChild = invertTree(root->right);
        root->right = lChild;
        root->left = rChild;
        return root;
    }
};

int main()
{
    cout << "226. Invert Binary Tree" << endl;

    return 0;
}


#endif
