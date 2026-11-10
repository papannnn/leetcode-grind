/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;
        
        ListNode* currL1 = l1;

        ListNode* currL2 = l2;

        int remainder = 0;
        while (currL1 && currL2) {
            int val = currL1->val + currL2->val + remainder;
            remainder = val >= 10;
            val = val % 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            currL1 = currL1->next;
            currL2 = currL2->next;
        }

        while (currL1) {
            int val = currL1->val + remainder;
            remainder = val >= 10;
            val = val % 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            currL1 = currL1->next;
        }

        while (currL2) {
            int val = currL2->val + remainder;
            remainder = val >= 10;
            val = val % 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            currL2 = currL2->next;
        }

        if (remainder) {
            curr->next = new ListNode(1);
        }

        return res->next;
    }
};
