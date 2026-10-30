class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int ROWS = heights.size(), COLS = heights[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> ans;
        // vector<type> v(n, val);
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int x, int y,
                                                                  vector<vector<bool>>& ocean) {
            // this is only called when valid
            ocean[x][y] = true;
            // we are doing from ocean to uphill -- reverse

            for (const auto& dir : directions) {
                int i = x + dir.first;
                int j = y + dir.second;
                // we continue if we are goind downhill (since reverse)
                if ((i < 0 || i >= ROWS) || (j < 0 || j >= COLS) || ocean[i][j] ||
                    heights[x][y] > heights[i][j]) {
                    continue;
                } else {
                    dfs(i, j, ocean);
                }
            }
        };

        for (int x = 0; x < ROWS; x++) {
            dfs(x, 0, pac);
            dfs(x, COLS - 1, atl);
        }
        for (int y = 0; y < COLS; y++) {
            dfs(0, y, pac);
            dfs(ROWS - 1, y, atl);
        }

        for (int x = 0; x < ROWS; x++) {
            for (int y = 0; y < COLS; y++) {
                if (pac[x][y] == true && atl[x][y] == true) {
                    ans.push_back({x, y});
                }
            }
        }

        return ans;
    }
};
