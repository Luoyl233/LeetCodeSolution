/*
 * 206. Reverse Linked List
 */


#include "common.h"


#if LEET_CODE == 206

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
    // Recursively
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

class Solution2 {
public:
    // Reverse linked list iteratively.
    ListNode* reverseList(ListNode* head) {
        // head insert
        ListNode* reversed = NULL;
        ListNode* tmp;
        while (head) {
            tmp = head;
            head = head->next;
            tmp->next = reversed;
            reversed = tmp;
        }
        return reversed;
    }
};

int main()
{
    cout << "206. Reverse Linked List" << endl;

    return 0;
}


#endif
