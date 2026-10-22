#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token.size() == 1 &&
                (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                switch (token[0]) {
                    case '+':
                        st.push(first + second);
                        break;
                    case '-':
                        st.push(first - second);
                        break;
                    case '*':
                        st.push(first * second);
                        break;
                    case '/':
                        st.push(first / second);
                        break;
                }
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
