class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> visited(nums.begin(),nums.end());
        return visited.size() < nums.size();

    }
};