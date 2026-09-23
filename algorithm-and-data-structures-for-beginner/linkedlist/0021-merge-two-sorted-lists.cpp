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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* headResult = new ListNode();
        ListNode* currResult = headResult;

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val) {
                currResult->next = new ListNode(curr1->val);
                currResult = currResult->next;
                curr1 = curr1->next;
            } else {
                currResult->next = new ListNode(curr2->val);
                currResult = currResult->next;
                curr2 = curr2->next;
            }

        }

        while (curr1 != nullptr) {
            currResult->next = new ListNode(curr1->val);
            currResult = currResult->next;
            curr1 = curr1->next;
        }

        while (curr2 != nullptr) {
            currResult->next = new ListNode(curr2->val);
            currResult = currResult->next;
            curr2 = curr2->next;
        }

        return headResult->next;
    }
};
