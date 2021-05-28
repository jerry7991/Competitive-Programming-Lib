#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "*") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y * x);
            } else if (tokens[i] == "+") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(x + y);
            } else if (tokens[i] == "-") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y - x);
            } else if (tokens[i] == "/") {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y / x);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> token(n);
    for (int i = 0; i < n; i++) cin >> token[i];

    cout << (new Solution())->evalRPN(token) << endl;
}