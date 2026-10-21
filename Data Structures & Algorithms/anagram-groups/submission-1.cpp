class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> buckets;
        for (auto& s : strs) {
            // make a freq table
            vector<int> count(26, 0);

            for (char val : s) {
                count[val - 'a']++;
            }

            // convert the freq table to key
            //  f1-f2-f3
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += '-' + to_string(count[i]);
            }

            buckets[key].push_back(s);
        }

        for (auto& vec : buckets) {
            // we just need the vector of strings
            result.push_back(vec.second);
        }

        return result;
    }
};
