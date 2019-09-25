/*
 * 234. Palindrome Linked List
 */


#include "common.h"


#if LEET_CODE == 234

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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        for (ListNode* p=head; p; p=p->next)
            len ++;

        // Reverse front half
        ListNode* leftHalf = NULL;
        for (int i=0; i < len /2; i++) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = leftHalf;
            leftHalf = tmp;
        }

        if (len % 2 == 1) { // skip mid when length is odd
            head = head->next;
        }
        while(head) {
            if (head->val != leftHalf->val)
                return false;
            head = head->next;
            leftHalf = leftHalf->next;
        }

        return true;
    }
};

int main()
{
    cout << "234. Palindrome Linked List" << endl;

    return 0;
}


#endif
