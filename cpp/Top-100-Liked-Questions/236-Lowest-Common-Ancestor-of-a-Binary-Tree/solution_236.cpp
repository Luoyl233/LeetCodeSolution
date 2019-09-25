/*
 * 236. Lowest Common Ancestor of a Binary Tree
 */


#include "common.h"


#if LEET_CODE == 236

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
    TreeNode* ans;

    // HashTable, O(logn)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;

        findRecursively(root, p, q);

        return ans;
    }

    bool findRecursively(TreeNode* root, TreeNode* p, TreeNode *q) {
        if (root == NULL || ans != NULL)
            return false;

        int flag = 0;
        if (root == p || root == q) flag ++;

        flag += findRecursively(root->left, p, q);

        flag += findRecursively(root->right, p, q);

        if (flag >= 2)
            ans = root;

        return flag > 0;
    }
};

int main()
{
    cout << "236. Lowest Common Ancestor of a Binary Tree" << endl;

    return 0;
}


#endif
