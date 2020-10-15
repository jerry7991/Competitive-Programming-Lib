#include <iostream>
#include <stack>
using namespace std;
stack<int> _push(int arr[], int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.size() == 0 || st.top() >= arr[i]) {
            st.push(arr[i]);
        } else {
            st.push(st.top());
        }
    }
    return st;
}
void _getMinAtPop(stack<int> s) {
    // your code here
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        stack<int> st = _push(arr, n);
        _getMinAtPop(st);
    }
    return 0;
}