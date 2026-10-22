class MyHashSet {
public:
    MyHashSet() {
        
    }

    void add(int key) {
        if (contains(key)) {
            return;
        }

        if (size == capacity) {
            capacity *= 2;
            size = 0;
            vector<list<int>> temp(capacity);
            for (int i = 0 ; i < bucket.size(); i++) {
                for (auto val : bucket[i]) {
                    insert(temp, val);
                }
            }
            bucket = std::move(temp);
        }

        insert(bucket, key);
    }
    
    void remove(int key) {
        if (!contains(key)) {
            return;
        }

        bucket[key % bucket.size()].remove_if([key](int val) {
            return val == key;
        });
    }
    
    bool contains(int key) {
        return find(bucket[key % bucket.size()].begin(), bucket[key % bucket.size()].end(), key) != bucket[key % bucket.size()].end();
    }

private:
    size_t size{};
    size_t capacity{8};
    vector<list<int>> bucket = vector<list<int>>(8);

    void insert(vector<list<int>>& bucket, int key) {
        bucket[key % bucket.size()].push_back(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */