/*
 * 2. Add Two Numbers
 */


#include "common.h"


#if LEET_CODE == 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TODO: Optimize code
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rt = NULL;
        ListNode *tail = rt;
        ListNode *p = l1, *q = l2;
        int sum = 0;
        int carry = 0;

        //cycle compute sum
        while(p && q) {
            sum = p->val + q->val + carry;
            carry = 0;
            while (sum >= 10){
                sum -= 10;
                carry += 1;
            }
            ListNode *newNode = new ListNode(sum);

            //add new node to tail
            if(!rt)
                rt = newNode;
            else
                tail->next = newNode;
            tail = newNode;

            //update var
            p = p->next;
            q = q->next;
        }

        //add rest to result
        ListNode *restNode = p;
        if(q)   restNode = q;
        while(restNode) {
            sum = restNode->val + carry;
            carry = 0;
            while (sum >= 10){
                sum -= 10;
                carry += 1;
            }
            ListNode *newNode = new ListNode(sum);
            if(!rt)
                rt = newNode;
            else
                tail->next = newNode;
            tail = newNode;

            restNode = restNode->next;
        }

        //at last, carry may not be 0
        if(carry > 0) {
            ListNode *newNode = new ListNode(carry);
            tail->next = newNode;
            tail = newNode;
        }

        return rt;
    }
};

int main()
{
    cout << "2. Add Two Numbers" << endl;

    return 0;
}


#endif
