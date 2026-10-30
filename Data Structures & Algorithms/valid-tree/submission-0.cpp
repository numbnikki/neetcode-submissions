class Solution {
    unordered_map<int, vector<int>> node;
    unordered_set<int> visited;

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Valid Tree = No Loop
        // No strays
        // no. of edges = n - 1 ; n = no. of nodes
        if (edges.size() > n - 1 || edges.size() < n - 1) return false;

        for (int i = 0; i < n; i++) {
            node[i] = {};
        }
        for (const auto& edge : edges) {
            node[edge[0]].push_back(edge[1]);
            node[edge[1]].push_back(edge[0]);
        }
        if (!dfs(0, -1)) return false;
        return visited.size() == n;
    }

   private:
    bool dfs(int cur, int parent) {
        if (visited.contains(cur)) return false;

        visited.insert(cur);

        for (int x : node[cur]) {
            if (x == parent) continue;
            if (!dfs(x, cur)) return false;
        }
        return true;
    }
};
