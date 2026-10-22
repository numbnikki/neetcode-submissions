class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> st;
        for (char ch : s) {
            if (ch == '[' || ch == '{' || ch == '(')
                st.push(ch);
            else if (!st.empty()) {
                switch (ch) {
                    case ']':
                        if (st.top() != '[')
                            return false;
                        else
                            st.pop();
                        break;
                    case '}':
                        if (st.top() != '{')
                            return false;
                        else
                            st.pop();
                        break;
                    case ')':
                        if (st.top() != '(')
                            return false;
                        else
                            st.pop();
                        break;
                }
            } else
                return false;
        }
        return st.empty();
    }
};
