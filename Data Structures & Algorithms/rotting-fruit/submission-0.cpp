class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int time = 0;
        int fresh = 0;

        int rows = grid.size(), cols = grid[0].size();

        // Populate queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (fresh > 0 && !que.empty()) {
            // do it in batches
            // 1 batch = 1 unit of time
            // to quantize the batches --> just use a loop
            int quanta = que.size();

            for (int unit = 0; unit < quanta; unit++) {
                // dequeue
                // go 4 directions
                // each direction if its a fresh fruit,
                // spoil it, decrement fresh counter, push the i,j to queue
                auto cur = que.front();
                que.pop();

                int i = cur.first;
                int j = cur.second;

                for (const auto& dir : directions) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    // dont forget to check bounds
                    if ((x >= 0 && x < rows) && (y >= 0 && y < cols) && grid[x][y] == 1) {
                        grid[x][y] = 2;  // 1-> fresh; 2-> rotten
                        fresh--;
                        que.push({x, y});
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
