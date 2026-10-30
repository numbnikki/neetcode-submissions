class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size(), -1);

        function<int(int)> dfs = [&](int i) -> int {
            if (i >= nums.size()) return 0;
            if (cache[i] != -1) return cache[i];
            // rob i
            int a = nums[i] + dfs(i + 2);
            // skip i
            int b = dfs(i + 1);
            cache[i] = max(a, b);
            return cache[i];
        };

        return (dfs(0));
    }
};
