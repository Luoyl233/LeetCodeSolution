/*
 * 98. Validate Binary Search Tree
 */


#include "common.h"


#if LEET_CODE == 98

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TODO: Optimize
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        return validateBST(root, 0x8000000000000000, 0x7fffffffffffffff);
    }

private:
    //bad sulution use INT_MIN && INT_MAX
    bool validateBST(TreeNode* root, long low, long high) {
      if (root == nullptr)  return true;
      else if (low >= root->val || high <= root->val)   return false;
      else return validateBST(root->left, low, root->val) &
              validateBST (root->right, root->val, high);

    }

};

int main()
{
    cout << "98. Validate Binary Search Tree" << endl;

    return 0;
}


#endif
