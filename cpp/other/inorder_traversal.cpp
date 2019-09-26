/*
 * 94. Binary Tree Inorder Traversal
*/

#include "common.h"
#include <vector>
#include <stack>

using namespace std;


#if LEET_CODE == 94

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > st;
        TreeNode *p = root;

        if (root == NULL)
            return res;

        do {
            while (p != NULL) {
                st.push(p);
                p = p->left;
            }

            p = st.top(); st.pop();
            res.push_back(p->val);
            p = p->right;
        } while (!st.empty() || p != NULL);

        return res;
    }

private:
    void inorder(TreeNode* root, vector<int> &res) {
        if (root == NULL)   return ;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};


int main()
{



}


#endif
