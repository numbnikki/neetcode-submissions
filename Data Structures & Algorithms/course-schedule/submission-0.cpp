class Solution {
    unordered_map<int, vector<int>> course;
    unordered_set<int> visited;

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // courses --> node
        // prerequisites --> edges
        // we are basically given an adjencey list
        // Directed graph

        // convert
        for (int i = 0; i < numCourses; i++) {
            course[i] = {};
        }
        for (auto& req : prerequisites) {
            course[req[0]].push_back(req[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int i) {
        if (visited.contains(i)) return false;  // cycle
        if (course[i].empty()) return true;

        visited.insert(i);
        for (int x : course[i]) {
            if (!dfs(x)) return false;
        }
        // all i prereqs can be done
        visited.clear();
        course[i].clear();
        return true;
    }
};
