/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* res = new Node(0);
        Node* resCurr = res;
        int idx = 0;
        unordered_map<Node*, int> mapping;
        vector<Node*> arrNode;
        for (Node* curr = head; curr != nullptr ; curr = curr->next, idx++) {
            mapping[curr] = idx;
            resCurr->next = new Node(curr->val);
            resCurr = resCurr->next;
            arrNode.push_back(resCurr);
        }

        idx = 0;
        for (Node* curr = head; curr != nullptr ; curr = curr->next, idx++) {
            if (curr->random) {
                arrNode[idx]->random = arrNode[mapping[curr->random]];
            }
        }

        return res->next;
    }
};
