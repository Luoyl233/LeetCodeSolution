/*
 * 98. Validate Binary Search Tree
 * try not use INT_MAX && INT_MIN!
*/

#include "common.h"
#include <stdlib.h>

using namespace std;


#if LEET_CODE == 98

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        return validateBST(root, 0x8000000000000000, 0x7fffffffffffffff);
//        return validateBST(root->left, root) & validateBST(root->right, root);
    }

private:
    //bad sulution use INT_MIN && INT_MAX
    bool validateBST(TreeNode* root, long low, long high) {
      if (root == nullptr)  return true;
      else if (low >= root->val || high <= root->val)   return false;
      else return validateBST(root->left, low, root->val) &
              validateBST (root->right, root->val, high);

    }

    //wrong sulution
    bool validateBST(TreeNode *root, TreeNode *prev) {
        if (root == nullptr)    return true;
        else if (prev->left == root && prev->val <= root->val)    return false;
        else if (prev->right == root && prev->val >= root->val)  return false;
        else return validateBST(root->left, root) & validateBST(root->right, root);
    }
};




#endif
