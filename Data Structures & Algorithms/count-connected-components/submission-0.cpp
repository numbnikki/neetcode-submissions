class Solution {
    unordered_set<int> visited;
    unordered_map<int, vector<int>> node;

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        for (int i = 0; i < n; i++) node[i] = {};

        for (const auto& edge : edges) {
            node[edge[0]].push_back(edge[1]);
            node[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (visited.contains(i))
                continue;
            else {
                ans++;
                dfs(i);
            }
        }
        return ans;
    }

   private:
    void dfs(int x) {
        if (visited.contains(x)) return;
        visited.insert(x);
        for (auto& nei : node[x]) {
            if (!visited.contains(nei)) dfs(nei);
        }
    }
};
