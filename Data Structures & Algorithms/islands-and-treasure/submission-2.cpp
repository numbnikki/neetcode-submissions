class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> que;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    que.push({i, j});
                }
            }
        }

        // Do in batches
        int distance = 0;
        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for (const auto& dir : directions) {
                int xx = x + dir.first;
                int yy = y + dir.second;

                if ((xx < 0 || xx >= ROWS) || (yy < 0 || yy >= COLS) || (grid[xx][yy] != INT_MAX))
                    continue;
                grid[xx][yy] = grid[x][y] + 1;
                que.push({xx, yy});
            }
        }
    }
};
