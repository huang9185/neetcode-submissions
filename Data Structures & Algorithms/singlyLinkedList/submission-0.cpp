class LinkedList {
    struct Node {
        int val;
        Node* next;
    };
    Node* head;
    int length = 0;
public:
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        if (index >= length) return -1;
        int i = 0;
        Node* cur = head;
        while (i != index) {
            ++i;
            cur = cur->next;
        }
        return cur->val;
    }

    void insertHead(int val) {
        Node* tmp = new Node{val, nullptr};
        tmp->next = head;
        head = tmp;
        ++length;
    }
    
    void insertTail(int val) {
        Node* prev = nullptr;
        Node* cur = head;
        while(cur) {
            prev = cur;
            cur = cur->next;
        }
        if (prev) {
            prev->next = new Node{val, nullptr};
        } else head = new Node{val, nullptr};
        ++length;
    }

    bool remove(int index) {
        if (index >= length) return false;
        int i = 0;
        Node* prev = nullptr;
        Node* cur = head;
        while (i != index) {
            prev = cur;
            cur = cur->next;
            ++i;
        }
        if (prev) {
            prev->next = cur->next;
        } else {
            head = cur->next;
        }
        delete cur;
        length--;
        return true;
    }

    vector<int> getValues() {
        vector<int> res(length);
        Node*cur = head;
        for (int i = 0; i < length; ++i) {
            res[i] = cur->val;
            cur = cur->next;
        }
        return res;
    }
};
