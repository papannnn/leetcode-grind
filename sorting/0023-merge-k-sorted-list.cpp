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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* currRes = res;

        while (true) {
            ListNode* curr = nullptr;
            int idx = -1;
            int num = 0;
            for (int i = 0 ; i < lists.size(); i++) {
                if (lists[i] == nullptr) {
                    continue;
                }

                num++;
                //
                if (curr == nullptr) {
                    curr = lists[i];
                    idx = i;
                    continue;
                }

                if (curr->val > lists[i]->val) {
                    curr = lists[i];
                    idx = i;
                }
            }

            if (num == 1) {
                currRes->next = curr;
                break;
            }

            if (curr != nullptr) {
                currRes->next = curr;
                currRes = currRes->next;
                lists[idx] = lists[idx]->next;
            } else {
                break;
            }
        }
        return res->next;
    }
};
