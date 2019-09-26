/*
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 */


#include "common.h"


#if LEET_CODE == 105

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode *constructTree(vector<int>& preorder, int left1, int right1, vector<int>& inorder, int left2, int right2) {
        if (left1 > right1)
            return NULL;

        int pivot = preorder[left1];
        TreeNode *node = new TreeNode(pivot);

        // Find pivot in inorder.
        int pivotIdx = left2;
        while (inorder[pivotIdx] != pivot)
            pivotIdx ++;

        node->left = constructTree(preorder, left1+1, left1+(pivotIdx-left2), inorder, left2, pivotIdx-1);
        node->right = constructTree(preorder, left1+(pivotIdx-left2)+1, right1, inorder, pivotIdx+1, right2);

        return node;
    }
};

int main()
{
    cout << "105. Construct Binary Tree from Preorder and Inorder Traversal" << endl;

    return 0;
}


#endif
