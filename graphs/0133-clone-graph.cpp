/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* generate(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (mapping.find(node->val) != mapping.end()) {
            return mapping[node->val];
        }

        Node* createdNode = new Node(node->val);
        mapping[node->val] = createdNode;
        for (int i = 0 ; i < node->neighbors.size(); i++) {
            createdNode->neighbors.push_back(generate(node->neighbors[i]));
        }

        return createdNode;
    }

    Node* cloneGraph(Node* node) {
        return generate(node);
    }

private:
    unordered_map<int, Node*> mapping;
};
