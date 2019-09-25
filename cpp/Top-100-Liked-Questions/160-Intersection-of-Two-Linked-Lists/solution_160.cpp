/*
 * 160. Intersection of Two Linked Lists
 */


#include "common.h"


#if LEET_CODE == 160

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;

        if (pA == NULL || pB == NULL)
            return NULL;

        while(pA && pB && pA != pB) {
            pA = pA->next;
            pB = pB->next;

            if (pA == pB)
                break;

            if (pA == NULL)
                pA = headB;
            if (pB == NULL)
                pB = headA;
        }
        return pA;
    }
};

int main()
{
    cout << "160. Intersection of Two Linked Lists" << endl;

    return 0;
}


#endif
