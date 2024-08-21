struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key{key}, val{val}, next{nullptr}, prev{nullptr} {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        remove(it->second);
        add(it->second);
        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            remove(it->second);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        add(newNode);
        if (cache.size() > capacity) {
            Node* toDelete = tail->prev;
            remove(toDelete);
            cache.erase(toDelete->key);
        }
    }

    void add(Node* node) {
        Node* nextHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextHead;
        nextHead->prev = node;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */