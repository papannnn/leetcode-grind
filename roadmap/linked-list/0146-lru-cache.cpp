class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;   
    }
    
    int get(int key) {
        if (mapping.find(key) == mapping.end()) {
            return -1;
        }

        auto it = mapping[key];
        linkedList.splice(linkedList.begin(), linkedList, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if (mapping.find(key) != mapping.end()) {
            auto it = mapping[key];
            it->second = value;
            linkedList.splice(linkedList.begin(), linkedList, it);
            return;
        }

        if (linkedList.size() == _cap) {
            int val = linkedList.back().first;
            linkedList.pop_back();
            mapping.erase(val);
        }

        linkedList.push_front(make_pair(key, value));
        mapping[key] = linkedList.begin();
    }

private:
    list<pair<int, int>> linkedList;
    unordered_map<int, list<pair<int, int>>::iterator> mapping;
    int _cap{};
};
