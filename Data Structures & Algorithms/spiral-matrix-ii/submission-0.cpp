class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 1;

        // Spiral matrix traversal
        int left = 0, right = n;
        int top = 0, bottom = n;
        while (left < right && top < bottom) {
            // go left along top border
            for (int j = left; j < right; j++) ans[top][j] = x++;

            top++;

            // got down alogn right border
            for (int i = top; i < bottom; i++) ans[i][right - 1] = x++;

            right--;
            // check if any elements left
            if (!(left < right && top < bottom)) break;

            // go left along bottom border
            for (int j = right - 1; j >= left; j--) ans[bottom - 1][j] = x++;
            bottom--;

            // go up along left border
            for (int i = bottom - 1; i >= top; i--) ans[i][left] = x++;
            left++;
        }
        return ans;
    }
};
/*
  |[Top,left] - [Top, 1] - [Top,2] ...... [Top, right]
  |[2, left]                              .
  |.                                      .
  |.                                      .
  |.                                      .
  |.                                      .
  |.                                      .
  |[bottom,left] - .......................[bottom, right]
*/