class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int ans = 0;
        while (r < prices.size()) {
            int profit = prices[r] - prices[l];
            ans = max(ans, profit);
            if (prices[l] > prices[r])
                l++;
            else
                r++;
        }
        return ans;
    }
};
