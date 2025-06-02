class MedianFinder {
    double result;
    multiset<int> Multiset;
    multiset<int>::iterator it;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        Multiset.insert(num);
        int n = Multiset.size();
        if (n == 1) {
            it = Multiset.begin();
            result = *it;
            return;
        }
        // 00X00
        if (n % 2 == 1) {
            if (num >= *it) {
                it = next(it, 1);
            }
            result = *it;
        } else {
            if (num < *it) {
                it = prev(it, 1);
            }
            result = *it * 0.5 + *(next(it, 1)) * 0.5;
        }
    }
    
    double findMedian() {
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */