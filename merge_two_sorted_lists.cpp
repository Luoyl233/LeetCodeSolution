/*
 * 21. Merge Two Sorted Lists
*/

#include "common.h"


#if LEET_CODE == 21

struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *p, *tail;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p = l1;
                l1 = l1->next;
            }
            else {
                p = l2;
                l2 = l2->next;
            }
            p->next = NULL;

            if (head == NULL)
                head = p;
            else
                tail->next = p;
            tail = p;
        }

        p = (l1 != NULL) ? l1 : l2;
        while (p != NULL) {
            if (head == NULL) {
                head = p;
                tail = p;
            }
            else
                tail->next = p;
            tail = p;
            p = p->next;
        }

        return head;
    }
};

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = new ListNode(0);

    ListNode *res = Solution().mergeTwoLists(l1, l2);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}

#endif
