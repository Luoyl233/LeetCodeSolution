/*
 * 145. Binary Tree Postorder Traversal
 * find more in discuss!
*/


#include "common.h"
#include <vector>
#include <stack>
#include <list>

using namespace std;

#if LEET_CODE == 145


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        list<int> reverse;
        vector<int> res;
        TreeNode *p;
        stack<TreeNode *> st;

        if (root == NULL)
            return res;

        st.push(root);
        while (!st.empty()) {
           p = st.top();
           st.pop();
           reverse.push_front(p->val);
           if (p->left) st.push(p->left);
           if (p->right) st.push(p->right);
        }

        for (int n : reverse)
            res.push_back(n);

        return res;
    }
};

int main()
{


    return 0;
}



#endif
