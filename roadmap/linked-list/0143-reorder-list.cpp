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
    void reorderList(ListNode* head) {
        cout << head->val << endl;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }

        ListNode* first = head;
        ListNode* second = slow;
        ListNode* curr = first;

        while (curr->next != second) {
            curr = curr->next;
        }
        curr->next = nullptr;

        ListNode* currSecond = second;
        ListNode* prev = nullptr;
        while (currSecond != nullptr) {
            ListNode* next = currSecond->next;
            currSecond->next = prev;
            prev = currSecond;
            currSecond = next;
        }

        second = prev;
        while (first && second) {
            ListNode* nextFirst = first->next;
            first->next = second;
            first = nextFirst;

            ListNode* nextSecond = second->next;
            second->next = first;
            second = nextSecond;
        }
    }
};
