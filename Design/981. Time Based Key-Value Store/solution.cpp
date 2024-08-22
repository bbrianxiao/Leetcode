class TimeMap {
    map<int, unordered_map<string, string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            if (it->first <= timestamp && it->second.count(key)) {
                return it->second[key];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */