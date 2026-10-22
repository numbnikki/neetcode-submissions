class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> st;

        unordered_map<char, char> closeToOpen = {{']', '['}, {'}', '{'}, {')', '('}};
        for (char ch : s) {
            // stack has elements and the current ch is closing Parentheses
            if (closeToOpen.contains(ch)) {
                if (!st.empty() && closeToOpen[ch] == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                // ch is open Parentheses
                st.push(ch);
            }
        }
        // if stack is empty then all canceled out -> true
        return st.empty();
    }
};
