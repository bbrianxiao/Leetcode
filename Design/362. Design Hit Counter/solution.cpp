class HitCounter {
    queue<int> q;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
        int diff = timestamp - 300;
        while (!q.empty() && q.front() <= diff) {
            q.pop();
        }
    }
    
    int getHits(int timestamp) {
        int diff = timestamp - 300;
        while (!q.empty() && q.front() <= diff) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */