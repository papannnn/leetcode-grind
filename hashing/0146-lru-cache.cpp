struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node() {
        prev = nullptr;
        next = nullptr;
    }

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    void pushHead(int key, int val) {
        Node* node = new Node(key, val);
        Node* nextHead = head->next;
        head->next = node;
        node->prev = head;
        nextHead->prev = node;
        node->next = nextHead;
    }

    void pushHead(Node* node) {
        Node* nextHead = head->next;
        head->next = node;
        node->prev = head;
        nextHead->prev = node;
        node->next = nextHead;
    }

    void takeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    Node* getTail() {
        Node* node = tail->prev;
        return node;
    }

    void popTail() {
        Node* node = tail->prev;
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;
    }

    Node* getHead() {
        Node* node = head->next;
        return node;
    }


private:
    Node* head;
    Node* tail;
};


class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mapping.find(key) == mapping.end()) {
            return -1;
        }

        Node* node = mapping[key];
        linkedList.takeNode(node);
        linkedList.pushHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (mapping.find(key) != mapping.end()) {
            Node* node = mapping[key];
            linkedList.takeNode(node);
            linkedList.pushHead(node);
            node->val = value;
            return;
        }

        if (size == capacity) {
            Node* nodeDelete = linkedList.getTail();
            int keyDelete = nodeDelete->key;
            linkedList.popTail();
            mapping.erase(keyDelete);
            size--;
        }

        Node* node = new Node(key, value);
        mapping[key] = node;
        linkedList.pushHead(node);
        size++;
    }

private:
    unordered_map<int, Node*> mapping;
    LinkedList linkedList;
    int capacity;
    int size{};
};
