class Solution {
public:
    int calPoints(vector<string>& operations) {
        int arr[operations.size()];
        int top = 0; // next empty position
        for (string op : operations) {
            if (isdigit(op[op.size()-1])) {
                arr[top++] = std::stoi(op);
                continue;
            }

            char o = op[0];
            if (o == '+') {
                arr[top++] = arr[top-1]+arr[top-2];
            } else if (o == 'D') {
                arr[top++] = arr[top-1]*2;
            } else if (o == 'C') {
                --top;
            }
        }

        int sum = 0;
        for (int i = 0; i < top; ++i) {
            sum += arr[i];
        }
        return sum;
    }
};