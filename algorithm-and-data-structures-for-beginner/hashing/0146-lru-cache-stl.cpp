struct Node {
    int key;
    int val;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        }

        linkedList.splice(linkedList.begin(), linkedList, hashMap[key]);
        return linkedList.front().val;
    }
    
    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            linkedList.splice(linkedList.begin(), linkedList, hashMap[key]);
            linkedList.front().val = value;
            return;
        }

        if (linkedList.size() == capacity) {
            hashMap.erase(linkedList.back().key);
            linkedList.pop_back();
        }
        
        linkedList.push_front({key, value});
        hashMap[key] = linkedList.begin();
    }

private:
    int capacity;
    list<Node> linkedList;
    unordered_map<int, list<Node>::iterator> hashMap;
};
