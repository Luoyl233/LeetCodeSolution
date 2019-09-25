/*
 * 142. Linked List Cycle II
 */


#include "common.h"


#if LEET_CODE == 142

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow && fast != NULL) {
                entry = head;
                while(entry != slow) {
                    slow = slow->next;
                    entry = entry->next;
                }
                break;
            }
        }
        return entry;
    }
};

int main()
{
    cout << "142. Linked List Cycle II" << endl;

    return 0;
}


#endif
