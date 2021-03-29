#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.length();
    stack<int> st;
    st.push(-1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (!st.size())
                st.push(i);
            else
                ans = max(ans, i - st.top());
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << longestValidParentheses(str);
}