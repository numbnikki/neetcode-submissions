class MinStack {
   public:
    stack<int> st;
    stack<int> mins;
    MinStack() {}

    void push(int val) {
        st.push(val);
        // mins might be empty check for that
        int curMin = mins.empty() ? val : min(mins.top(), val);
        mins.push(curMin);
    }

    void pop() {
        st.pop();
        mins.pop();
    }

    int top() { return st.top(); }

    int getMin() { return mins.top(); }
};
