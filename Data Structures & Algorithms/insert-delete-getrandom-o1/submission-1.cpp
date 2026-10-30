class RandomizedSet {
    unordered_map<int, int> hmap;
    vector<int> arr;

   public:
    RandomizedSet() {}

    bool insert(int val) {
        if (hmap.contains(val)) return false;
        hmap[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!hmap.contains(val)) return false;
        int val_index = hmap[val];
        int last = arr.back();

        // swap
        hmap[last] = val_index;
        arr[val_index] = last;

        // remvove the val
        arr.pop_back();
        hmap.erase(val);
        return true;
    }

    int getRandom() {
        // rand() -> int random
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */