class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        int islands = 0;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        function<void(int, int)> dfs = [&](int r, int c) {
            if ((r < 0 || r >= ROWS) || (c < 0 or c >= COLS)) return;
            if (grid[r][c] == '1') {
                grid[r][c] = 'V';  // mark visited
                for (const auto& dir : directions) {
                    dfs(r + dir.first, c + dir.second);
                }
            }
        };

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j);
                }
            }
        }
        return islands;
    }
};
