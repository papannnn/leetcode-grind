class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        auto it = mapping[key].upper_bound(timestamp);
        if (it == mapping[key].begin()) {
            return "";
        }

        return prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> mapping;
};
