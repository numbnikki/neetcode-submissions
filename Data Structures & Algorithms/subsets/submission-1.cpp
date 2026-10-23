class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        function<void(int)> dfs = [&](int index) {
            if (index == nums.size()) {
                ans.push_back(subset);  // Save a copy of the current subset
                return;
            }

            // include nums[index]
            subset.push_back(nums[index]);
            dfs(index + 1);

            // exclude nums[index]
            subset.pop_back();
            dfs(index + 1);
        };

        dfs(0);
        return ans;
    }
};
