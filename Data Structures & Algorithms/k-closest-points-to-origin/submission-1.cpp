class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // {dist, {x, y}}
        // pair<int, {}>
        // pair<int, pair<int,int>>

        priority_queue<pair<int, pair<int, int>>> max_heap;
        vector<vector<int>> ans;

        for (const auto& point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];

            max_heap.push({distance, {point[0], point[1]}});

            while (max_heap.size() > k) {

                max_heap.pop();
            }
        }

        while (!max_heap.empty()) {
            auto cood = max_heap.top().second;
            ans.push_back({cood.first, cood.second});
            max_heap.pop();
        }

        return ans;
    }
};
