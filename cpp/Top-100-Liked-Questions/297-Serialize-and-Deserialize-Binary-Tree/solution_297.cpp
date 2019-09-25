/*
 * 297. Serialize and Deserialize Binary Tree
 */


#include "common.h"


#if LEET_CODE == 297

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream buf;
        if (root == NULL)
            return buf.str();

        queue<TreeNode*> q;
        q.push(root);
        buf << root->val;

        while (!q.empty()) {
            TreeNode *r = q.front(); q.pop();
            if (r->left) {
                buf << " " << r->left->val;
                q.push(r->left);
            } else
                buf<< " " << "N";

            if (r->right) {
                buf << " " << r->right->val;
                q.push(r->right);
            } else
                buf<< " " << "N";
        }

        return buf.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        TreeNode *root = NULL;

        if (data.size() == 0)
            return root;

        string s;
        istringstream in(data);
        in >> s;
        root = new TreeNode(stoi(s));
        q.push(root);

        while(!q.empty()) {
            TreeNode *r = q.front(); q.pop();

            in >> s;
            if (s != "N") {
                r->left = new TreeNode(stoi(s));
                q.push(r->left);
            }

            in >> s;
            if (s != "N") {
                r->right = new TreeNode(stoi(s));
                q.push(r->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main()
{
    cout << "297. Serialize and Deserialize Binary Tree" << endl;

    return 0;
}


#endif
