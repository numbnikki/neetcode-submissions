class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> visited;

        for(auto num: nums){
            if (visited.contains(num)) return true;
            visited.insert(num);
        }
        return false;
    }
};