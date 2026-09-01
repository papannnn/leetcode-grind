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
    ListNode* recursive(ListNode* prev, ListNode* curr) {
        ListNode* next = nullptr;
        if (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
        }

        if (next == nullptr) {
            return curr;
        }

        return recursive(curr, next);
    }

    ListNode* reverseList(ListNode* head) {
        return recursive(nullptr, head);
    }
};