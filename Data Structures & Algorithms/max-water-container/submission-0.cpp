class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            int area = (r - l) * min(heights[r], heights[l]);
            ans = max(area, ans);

            if (heights[l] <= heights[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};
