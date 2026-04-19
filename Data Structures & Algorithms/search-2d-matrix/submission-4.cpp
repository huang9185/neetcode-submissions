class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // want to use the lower bound function on vertical search
        // on the first item per row
        auto it = lower_bound(matrix.begin(), matrix.end(), target,
            [](vector<int>& l, int target) {
                return l[0] < target;
            });
        int i = distance(matrix.begin(), it);
        // if not end (meaning exists one not less than)
        if (i != matrix.size()) {
            if (matrix[i][0] == target) return true;
            if (i == 0) return false;
            int row = i-1;
            return binary_search(matrix[row].begin(), matrix[row].end(), target);
        }
        //  if equal, return
        //  if not equal, check previous row 
        //      if previous row exists, binary search
        //      else return false
        // if is end, check last row (it does)
        int row = i-1;
        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};
