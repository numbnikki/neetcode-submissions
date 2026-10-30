class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int ans = 0;
        int curLen = 1;

        // find a start and see how long it goes

        for (int& x : nums) {
            if (!numSet.contains(x - 1)) {
                int curLen = 1;

                while (numSet.contains(x + curLen)) curLen++;
                ans = max(curLen, ans);
            }
        }
        return ans;
    }
};
