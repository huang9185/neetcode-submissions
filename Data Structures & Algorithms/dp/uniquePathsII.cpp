class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        res[0][0] = obstacleGrid[0][0]? 0 : 1;
        for (int i = 1; i < m; ++i) 
            res[i][0] = obstacleGrid[i][0] || res[i-1][0] == 0? 0 : 1;
        for (int j = 1; j < n; ++j) 
            res[0][j] = obstacleGrid[0][j] || res[0][j-1] == 0? 0 : 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) res[i][j] = 0;
                else res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};
