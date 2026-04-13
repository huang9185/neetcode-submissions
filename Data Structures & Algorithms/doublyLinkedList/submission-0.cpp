struct N {
    N* p;
    N* n;
    int v;
};

class MyLinkedList {
    N* left;
    N* right;
public:
    MyLinkedList() {
        left = new N{nullptr, nullptr, 0};
        right = new N{nullptr, nullptr, 0};
        left->n = right;
        right->p = left;
    }
    
    int get(int index) {
        N* c = left->n;
        int i = 0;
        while (c && i < index) {
            ++i;
            c = c->n;
        }
        if (c && index == i && c != right) return c->v;
        return -1;
    }
    
    void addAtHead(int val) {
        N* tmp = new N{left, left->n, val};
        left->n->p = tmp;
        left->n = tmp;
    }
    
    void addAtTail(int val) {
        N* tmp = new N{right->p, right, val};
        right->p->n = tmp;
        right->p = tmp;
    }
    
    void addAtIndex(int index, int val) {
        N* c = left->n;
        int i = 0;
        for (; i < index && c; ++i) c = c->n;
        if (c && i == index) {
            N* tmp = new N{c->p, c, val};
            c->p->n = tmp;
            c->p = tmp;
        }
    }
    
    void deleteAtIndex(int index) {
        N* c = left->n;
        int i = 0;
        for (; i < index && c; ++i) c = c->n;
        if (c && i == index && c != right) {
            c->n->p = c->p;
            c->p->n = c->n;
            delete c;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

