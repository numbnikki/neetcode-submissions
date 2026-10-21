class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ind; // <val,index> || val-->index
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ind[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (ind.contains(diff) && ind[diff] != i)
                return {i, ind[diff]};
        }
        return {};
    }
};
