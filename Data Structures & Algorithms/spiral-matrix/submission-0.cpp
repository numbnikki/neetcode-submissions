class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();
        vector<int> ans;
        while (left < right && top < bottom) {
            // go right
            for (int j = left; j < right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            // go down
            for (int i = top; i < bottom; i++) {
                ans.push_back(matrix[i][right - 1]);
            }
            right--;
            // since they are changed, check again
            if (!(left < right && top < bottom)) break;
            // go left
            for (int j = right - 1; j >= left; j--) {
                ans.push_back(matrix[bottom - 1][j]);
            }
            bottom--;
            // go up
            for (int i = bottom - 1; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
