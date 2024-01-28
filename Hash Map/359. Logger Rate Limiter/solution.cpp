class Logger {
public:
    map<string, int> m;
    Logger() {
        m.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.find(message) == m.end()) {
            m[message] = timestamp + 10;
            return true;
        } else {
            if (m[message] > timestamp) {
                return false;
            } else {
                m[message] = timestamp + 10;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */