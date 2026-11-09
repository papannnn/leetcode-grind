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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr;
        int numNode = 0;
        for (ListNode* curr = head; curr ; curr = curr->next) {
            numNode++;
        }

        int delIdx = numNode - n;
        if (delIdx == 0) {
            return head->next;
        }

        int idx = 1;
        for (ListNode* curr = head; curr ; curr = curr->next, idx++) {
            if (idx == delIdx) {
                curr->next = curr->next->next;
            }
        }
        return head;
    }
};
