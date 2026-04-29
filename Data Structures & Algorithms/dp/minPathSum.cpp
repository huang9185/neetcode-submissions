class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // each spot keeps min sum for the path ending in its block
        vector<vector<int>> s(m, vector<int>(n));
        s[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) s[i][0] = grid[i][0] + s[i-1][0];
        for (int j = 1; j < n; ++j) s[0][j] = grid[0][j] + s[0][j-1];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int top = s[i-1][j], left = s[i][j-1];
                s[i][j] = min(top, left) + grid[i][j];
            }
        }
        return s[m-1][n-1];
    }
};

