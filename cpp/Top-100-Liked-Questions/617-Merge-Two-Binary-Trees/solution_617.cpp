/*
 * 617. Merge Two Binary Trees
 */


#include "common.h"


#if LEET_CODE == 617


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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* node = NULL;
        if (t1 != NULL) {
            node = t1;
            if (t2 != NULL) {
                node->left = mergeTrees(t1->left, t2->left);
                node->right = mergeTrees(t1->right, t2->right);
                node->val += t2->val;
            }
        } else if (t2 != NULL) {
            node = t2;
        }

        return node;
    }
};


int main()
{
    cout << "617. Merge Two Binary Trees" << endl;

    return 0;
}


#endif
