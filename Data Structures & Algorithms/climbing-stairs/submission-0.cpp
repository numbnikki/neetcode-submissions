class Solution {
   public:
    int climbStairs(int n) {
        unordered_map<int, int> cache;
        function<int(int)> dp = [&](int x) -> int {
            if (cache.contains(x)) return cache[x];
            cache[x] = dp(x - 1) + dp(x - 2);
            return cache[x];
        };
        cache[1] = 1;
        cache[2] = 2;
        return dp(n);
    }
};
