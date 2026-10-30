class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());

        dp[0] = nums[0];  // robbed this since no rob no profit, tis max
        dp[1] = max(dp[0],
                    nums[1]);  // cant rob consec -- so rob this or prev -- so maximuse here is max

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
