/**
 * 92. Reverse Linked List II
 */

#include "common.h"

#if LEET_CODE == 92

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return head;

        int cnt = 1;
        ListNode *p = head;
        while (cnt < m) {
            if ()
            cnt ++;
            p = p->next;
        }
    }

    ListNode* doReversion(ListNode *head, int m, int n, int cnt) {
        if (head == NULL) return NULL;
        // If this node is between m and n
        return NULL;
    }
};

#endif
