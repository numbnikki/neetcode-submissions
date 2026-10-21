class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_count;  // integer -> frequency

        for (int x : nums) {
            freq_count[x]++;
        }

        // min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        // keep the size k, the smallest one is on top
        // so when k+1 is inserted
        // the smallest remaining is removed
        // resulting in the top-k elements upto k+1

        for (auto& element : freq_count) {
            // freq, int
            min_heap.push({element.second, element.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            // O(1)
            ans.push_back(min_heap.top().second);
            min_heap.pop(); // O(log(n))
        }
        return ans;
    }
};
