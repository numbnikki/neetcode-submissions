class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> buckets; // sorteds -> []
        for (string s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            buckets[sorted_s].push_back(s);
        }

        // now make the vector of <<vector of strings>>
        for (auto& vec : buckets) {
            // we just need the vector of strings
            result.push_back(vec.second);
        }

        return result;
    }
};
