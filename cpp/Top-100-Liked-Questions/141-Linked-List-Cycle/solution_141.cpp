/*
 * 141. Linked List Cycle
 */


#include "common.h"


#if LEET_CODE == 141

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
    bool hasCycle(ListNode *head) {
        ListNode* fast  = head;
        ListNode* slow = head;
        while (fast != NULL) {
            fast = fast->next == NULL ? NULL : fast->next->next;
            slow = slow->next;
            if (fast == slow && fast != NULL)
                return true;
        }
        return false;
    }
};

int main()
{
    cout << "141. Linked List Cycle" << endl;

    return 0;
}


#endif
