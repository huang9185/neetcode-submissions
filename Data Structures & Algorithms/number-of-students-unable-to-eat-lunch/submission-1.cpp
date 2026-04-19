class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        for (int s : students) st.push(s);
        int i = 0;
        int nrc = 0;
        while (!st.empty()) {
            if (nrc == st.size()) break;
            int sw = sandwiches[i];
            int stu = st.front();
            st.pop();
            // if student wants to eat
            if (sw == stu) {
                ++i;
                nrc = 0;
                continue;
            }
            ++nrc;
            st.push(stu);
        }
        return st.size();
    }
};