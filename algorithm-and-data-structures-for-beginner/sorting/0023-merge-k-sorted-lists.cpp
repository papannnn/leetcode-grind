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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* res = new ListNode();
        ListNode* resHead = res;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            } else {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }

        while (l1 != nullptr) {
            res->next = l1;
            res = res->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            res->next = l2;
            res = res->next;
            l2 = l2->next;
        }

        return resHead->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        while (lists.size() != 1) {
            vector<ListNode*> temp;
            temp.reserve(lists.size());

            for (int i = 0 ; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = nullptr;
                if (i + 1 < lists.size()) {
                    l2 = lists[i + 1];
                }

                temp.push_back(mergeList(l1, l2));
            }
            lists = move(temp);
        }
        return lists[0];
    }
};
