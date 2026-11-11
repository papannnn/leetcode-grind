struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    } 
};

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        sentinelRight = new Node(-1);
        sentinelLeft = new Node(-1);
        sentinelRight->left = sentinelLeft;
        sentinelLeft->right = sentinelRight;
    }
    
    bool enQueue(int value) {
        if (size == capacity) {
            return false;
        }

        size++;
        Node* node = new Node(value);

        node->left = sentinelRight->left;
        node->right = sentinelRight;

        sentinelRight->left->right = node;
        sentinelRight->left = node;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) {
            return false;
        }

        size--;
        
        Node* node = sentinelLeft->right;

        sentinelLeft->right = node->right;
        sentinelLeft->right->left = sentinelLeft;
        return true;
    }
    
    int Front() {
        return sentinelLeft->right->val;
    }
    
    int Rear() {
        return sentinelRight->left->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }

private:
    int capacity;
    int size;
    Node* sentinelLeft;
    Node* sentinelRight;  
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */