class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size(), COLS = board[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        function<bool(int, int, int)> dfs = [&](int x, int y, int i) -> bool {
            if (i == word.length()) return true;

            if (x < 0 || y < 0 || x >= ROWS || y >= COLS || board[x][y] != word[i] ||
                board[x][y] == 'V')
                return false;

            board[x][y] = 'V';
            bool temp = false;
            for (const auto& dir : directions) {
                temp = temp || dfs(x + dir.first, y + dir.second, i + 1);
            }
            board[x][y] = word[i];
            return temp;
        };

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }

        return false;
    }
};
