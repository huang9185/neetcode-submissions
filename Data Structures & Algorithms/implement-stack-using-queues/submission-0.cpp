class MyStack {
    queue<int> normal;
    queue<int> s;
    // out 1 2 3 in 4
    // 
public:
    MyStack() {
    }
    
    void push(int x) {
        normal.push(x);
    }
    
    int pop() {
        while(normal.size() != 1) {
            int a = normal.front();
            normal.pop();
            s.push(a);
        }
        int b = normal.front();
        normal.pop();
        normal = s;
        s = queue<int>();
        return b;
    }
    
    int top() {
        while(normal.size() != 1) {
            int a = normal.front();
            normal.pop();
            s.push(a);
        }
        int b = normal.front();
        s.push(b);
        normal = s;
        s = queue<int>();
        return b;
    }
    
    bool empty() {
        return normal.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */