class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (isOpen(c)) {
                st.push(c);
                continue;
            }
            if (st.empty()) {
                return false;
            } 
                
            char t = st.top();
            if (t == '(' && c == ')') st.pop();
            else if (t == '{' && c == '}') st.pop();
            else if (t == '[' && c == ']') st.pop();
            else return false;
        }
        if (st.empty()) return true;
        return false;
    }
    bool isOpen(char c) {
        return c == '(' || c == '{' || c == '[';
    }
};
