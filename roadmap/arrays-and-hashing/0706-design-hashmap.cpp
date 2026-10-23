class MyHashMap {
public:
    MyHashMap() {
        bucket.resize(capacity);
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            auto it = find_if(bucket[key % bucket.size()].begin(), bucket[key % bucket.size()].end(), [key] (const pair<int, int>& p) {
                return p.first == key;
            });
            it->second = value;
            return;
        }

        if (size == capacity) {
            capacity *= 2;
            vector<list<pair<int, int>>> temp(capacity);

            for (int i = 0 ; i < bucket.size(); i++) {
                for (auto &p : bucket[i]) {
                    int k = p.first;
                    temp[k % capacity].push_back(p);
                }
            }
            bucket = std::move(temp);
        }

        bucket[key % capacity].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        auto it = find_if(bucket[key % bucket.size()].begin(), bucket[key % bucket.size()].end(), [key] (const pair<int, int>& p) {
                return p.first == key;
            });

        if (it == bucket[key % bucket.size()].end()) {
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
        if (get(key) == -1) {
            return;
        }

        bucket[key % bucket.size()].remove_if([key] (const pair<int, int>& p) {
            return p.first == key;
        });
    }

private:
    int size{};
    int capacity{8};
    vector<list<pair<int, int>>> bucket;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */