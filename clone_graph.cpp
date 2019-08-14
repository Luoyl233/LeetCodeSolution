/*
 * 133. Clone Graph
*/

#include "common.h"
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


#ifdef CLONE_GRAPH

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        stack<Node *> st;
        Node *root = new Node(node->val, {});
        copies[node] = root;
        st.push(node);
        Node *curr, *p;
        vector<Node*> neighbors;
        while (!st.empty()) {
            curr = st.top();
            st.pop();
            neighbors = curr->neighbors;
            for (int i=0; i < neighbors.size(); i++) {
                if (copies.find(neighbors[i]) == copies.end()) {
                    p = new Node(neighbors[i]->val, {});
                    copies[neighbors[i]] = p;
                    st.push(neighbors[i]);
                }
                else
                    p = copies[neighbors[i]];
                copies[curr]->neighbors.push_back(p);
            }
        }
        return root;
    }

private:
    unordered_map<Node*, Node*> copies;
};

int main()
{


    return 0;
}

#endif
