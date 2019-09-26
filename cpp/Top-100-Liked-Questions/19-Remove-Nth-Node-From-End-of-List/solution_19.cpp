/*
 * 19. Remove Nth Node From End of List
 */


#include "common.h"


#if LEET_CODE == 19

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || head == NULL)
            return head;

        ListNode *prev = NULL, *cur = head, *p = head;
        for (; n > 1; n --)
            p = p->next;

        while (p->next != NULL) {
            p = p->next;
            prev = cur;
            cur = cur->next;
        }

        if (prev != NULL)
            prev->next = cur->next;
        else // cur is the first node
            head = head->next;

        return head;
    }
};

int main()
{
    cout << "19. Remove Nth Node From End of List" << endl;

    return 0;
}


#endif
