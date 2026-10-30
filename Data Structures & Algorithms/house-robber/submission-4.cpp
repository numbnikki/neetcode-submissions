class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int a = nums[0];  // robbed this since no rob no profit, tis max
        int b = max(a,
                    nums[1]);  // cant rob consec -- so rob this or prev -- so maximuse here is max

        for (int i = 2; i < nums.size(); i++) {
            int cur = max(nums[i] + a, b);
            a = b;
            b = cur;
        }
        return b;
    }
};
