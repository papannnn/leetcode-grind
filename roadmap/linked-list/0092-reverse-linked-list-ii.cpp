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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        ListNode* leftNode = head;
        ListNode* rightNode = head;

        ListNode* prevLeft = sentinel;
        for (int i = 1 ; i < left; i++) {
            leftNode = leftNode->next;
            prevLeft = prevLeft->next;
        }

        for (int i = 1; i < right; i++) {
            rightNode = rightNode->next;
        }

        ListNode* nextRight = rightNode->next;
        ListNode* currSwap = leftNode;
        ListNode* prev = nullptr;
        while (currSwap != nextRight) {
            ListNode* next = currSwap->next;
            currSwap->next = prev;
            prev = currSwap;
            currSwap = next;
        }

        prevLeft->next = rightNode;
        leftNode->next = nextRight;

        return sentinel->next;
    }
};