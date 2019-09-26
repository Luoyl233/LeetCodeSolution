/*
 * 23. Merge k Sorted Lists
*/

#include "common.h"
#include<iostream>
#include <queue>

using namespace std;


#if LEET_CODE == 23


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct comparator
{
    bool operator() (const ListNode *l, const ListNode *r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, comparator> pq;
        ListNode *head = NULL;
        ListNode *tail = NULL;

        for (ListNode *h: lists) {
            if (h != NULL)
                pq.push(h);
        }

        while (!pq.empty()) {
            ListNode *min = pq.top();
            pq.pop();

            ListNode *next = min->next;
            if (next != NULL)
                pq.push(next);

            if (head == NULL)
                head = min;
            else
                tail->next = min;
            tail = min;
            tail->next = NULL;
        }

        return head;
    }
};


int main()
{

    return 0;
}

#endif
