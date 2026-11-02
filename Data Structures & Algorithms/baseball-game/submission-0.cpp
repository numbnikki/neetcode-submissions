class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int total = 0;

        for (const string& s : operations) {
            if (s == "+") {
                int last = stk.top();
                stk.pop();
                int previous = stk.top();
                stk.push(last);

                int cur = previous + last;
                stk.push(cur);
                total += cur;
            } else if (s == "D") {
                int cur = stk.top() * 2;
                stk.push(cur);
                total += cur;
            } else if (s == "C") {
                total -= stk.top();
                stk.pop();
            } else {
                int cur = stoi(s);
                stk.push(cur);
                total += cur;
            }
        }

        return total;
    }
};