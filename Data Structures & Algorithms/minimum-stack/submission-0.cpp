class MinStack {
    // want to maintain two stacks
    // 1. the normal stack
    // 2. the min so far
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
    }
    
    // 1. push to normal stack
    // 2. if empty, is min; else, compare with previous; smaller one taks position
    void push(int val) {
        st.push(val);
        if (minst.empty()) minst.push(val);
        else {
            minst.push(min(minst.top(), val));
        }
    }
    
    // 2. pop as normal 
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
