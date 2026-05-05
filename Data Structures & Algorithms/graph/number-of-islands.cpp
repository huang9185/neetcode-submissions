class Solution {
    int m,n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        // call a function on coordinates
        // check if out of bounds, return
        // if visited, return
        // if island, connected to the one from caller, turn into water
        // then if water, return
        for (int i = 0 ; i < m; ++i ) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    visit(grid, i, j);
                }
            }
        }
        return res;
    }
    void visit(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (grid[x][y] == '0') return;
        grid[x][y] = '0';
        visit(grid, x+1, y);
        visit(grid, x-1, y);
        visit(grid, x, y+1);
        visit(grid, x, y-1);
    }
};

