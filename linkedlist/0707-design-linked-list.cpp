struct Node {
    int _val;
    Node* _next;
    Node* _prev;
    
    Node(int val): _val{val}, _next{nullptr}, _prev{nullptr} {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        _head = nullptr;
        _tail = nullptr;
        _length = 0;
    }
    
    int get(int index) {
        if (index >= _length) {
            return -1;
        }

        Node* curr = _head;
        for (int i = 0 ; i < index; i++) {
            curr = curr->_next;
        }
        return curr->_val;
    }
    
    void addAtHead(int val) {
        if (_head == nullptr) {
            _head = _tail = new Node(val);
            _length++;
            return;
        }

        Node* node = new Node(val);
        node->_next = _head;
        _head->_prev = node;
        _head = node;
        _length++;
    }
    
    void addAtTail(int val) {
        if (_head == nullptr) {
            _head = _tail = new Node(val);
            _length++;
            return;
        }

        Node* node = new Node(val);
        node->_prev = _tail;
        _tail->_next = node;
        _tail = node;
        _length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == _length) {
            addAtTail(val);
            return;
        }

        Node* curr = _head;
        for (int i = 0; i < index; i++) {
            curr = curr->_next;
        }

        Node* node = new Node(val);
        node->_next = curr;
        node->_prev = curr->_prev;
        curr->_prev->_next = node;
        curr->_prev = node;
        _length++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _length) {
            return;
        }
        
        if (_head == _tail) {
            delete _head;
            _head = nullptr;
            _tail = nullptr;
            _length = 0;
            return;
        }

        if (index == 0) {
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
            _length--;
            return;
        }

        if (index == _length - 1) {
            Node* temp = _tail;
            _tail = _tail->_prev;
            delete temp;
            _length--;
            return;
        }

        Node* curr = _head;
        for (int i = 0; i < index; i++) {
            curr = curr->_next;
        }

        curr->_prev->_next = curr->_next;
        curr->_next->_prev = curr->_prev;
        delete curr;
        _length--;
    }

private:
    Node* _head;
    Node* _tail;
    int _length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */