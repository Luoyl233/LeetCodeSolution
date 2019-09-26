/*
 * 114. Flatten Binary Tree to Linked List
 */


#include "common.h"


#if LEET_CODE == 114

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
    // void flatten(TreeNode* root) {
    //     preorderFlatten(root, NULL);
    // }

   TreeNode* head = NULL;

   // Optimal
    void flatten(TreeNode* root) {
        if (root != NULL) {
            flatten(root->right);
            flatten(root->left);
            root->right = head;
            root->left = NULL;
            head = root;
        }
    }

    // preorder: too complex
    TreeNode* preorderFlatten(TreeNode* root, TreeNode* tail) {
        if (root == NULL) {
            return NULL;
        } else {
            if (tail != NULL)
                tail->right = root;
            TreeNode* rightChild = root->right;
            root->right = NULL;
            TreeNode* leftTail = preorderFlatten(root->left, root);
            root->left = NULL;
            leftTail = leftTail == NULL ? root : leftTail;


            TreeNode* rightTail = preorderFlatten(rightChild, leftTail);
            return rightTail == NULL ? leftTail : rightTail;
        }
    }
};

int main()
{
    cout << "114. Flatten Binary Tree to Linked List" << endl;

    return 0;
}


#endif
