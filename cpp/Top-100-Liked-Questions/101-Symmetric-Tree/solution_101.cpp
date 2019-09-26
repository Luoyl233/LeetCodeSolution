/*
 * 101. Symmetric Tree
 */


#include "common.h"


#if LEET_CODE == 101

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            if (left == NULL && right == NULL)
                continue;
            if (!left || !right)
                return false;
            if (left->val != right->val)
                return false;
            q.push(left->left); q.push(right->right);
            q.push(left->right); q.push(right->left);
        }
        return true;
    }
};

// Postorder
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        else
            return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == right)
            return true;
        if (!left || !right)
            return false;
        return left->val == right->val
                && isSymmetric(left->left, right->right)
                && isSymmetric(left->right, right->left);
    }
};

int main()
{
    cout << "101. Symmetric Tree" << endl;

    return 0;
}


#endif
