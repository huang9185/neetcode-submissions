class LRUCache {
private: 
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
    };
    Node* head; // least recent
    Node* tail; // most recent
    int capacity, count;
    unordered_map<int, Node*> m;
    
    void add(Node* n) {
        n->next = tail;
        n->prev = tail->prev;
        tail->prev->next = n;
        tail->prev = n;
    }
    void remove(Node* n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        m.reserve(capacity);
        head = new Node{-1, -1, nullptr, nullptr};
        tail = new Node{-1, -1, head, nullptr};
        head->next = tail;
    }
    
    int get(int key) {
        if (m.count(key) != 0) {
            Node* pair = m[key];
            remove(pair);
            add(pair);
            return pair->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // Check existence
        if (m.count(key) != 0) {
            get(key);
            tail->prev->val = value;
            return;
        }
        
        if (count == capacity) {
            Node* pair = head->next;
            m.erase(pair->key);
            remove(pair);
            delete pair;
            --count;
        }
        Node* p = new Node{key, value, tail, nullptr};
        add(p);
        m[key] = p;
        ++count;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

