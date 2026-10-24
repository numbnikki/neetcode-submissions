class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        vector<vector<int>> ans;

        function<void(int, int)> dfs = [&](int index, int sum) {
            if (sum == target) {
                ans.push_back(subset);
                return;
            }
            if (index >= nums.size() or sum > target) {
                return;
            }

            // include index
            subset.push_back(nums[index]);
            dfs(index, sum + nums[index]);
            // exclude index
            subset.pop_back();
            dfs(index + 1, sum);
        };
        dfs(0, 0);
        return ans;
    }
};
