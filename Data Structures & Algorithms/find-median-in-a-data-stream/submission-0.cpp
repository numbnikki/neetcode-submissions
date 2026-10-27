class MedianFinder {
    priority_queue<int> lhs;
    priority_queue<int, vector<int>, greater<int>> rhs;

   public:
    MedianFinder() {}

    void addNum(int num) {
        // keep halfs sorted
        lhs.push(num);
        if (!rhs.empty() && lhs.top() > rhs.top()) {
            rhs.push(lhs.top());
            lhs.pop();
        }

        // balance the halfs
        if (lhs.size() > rhs.size() + 1) {
            rhs.push(lhs.top());
            lhs.pop();
        }

        if (rhs.size() > lhs.size() + 1) {
            lhs.push(rhs.top());
            rhs.pop();
        }
    }

    double findMedian() {
        if (lhs.size() == rhs.size()) {
            return (lhs.top() + rhs.top()) / 2.0;
        } else {
            if (lhs.size() > rhs.size()) {
                return lhs.top();
            } else
                return rhs.top();
        }
    }
};
