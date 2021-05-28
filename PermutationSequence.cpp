#include <bits/stdc++.h>
using namespace std;

vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void solve(string &ans, vector<int> &v, int n, int k) {
    if (n == 1) {
        // single element
        ans.append(to_string(v.back()));
        return;
    }
    int index = k / fact[n - 1];

    if (k % fact[n - 1] == 0) index--;

    ans.append(to_string(v[index]));
    v.erase(v.begin() + index);
    k -= fact[n - 1] * index;
    solve(ans, v, n - 1, k);
}

string getPermutation(int n, int k) {
    if (n == 1) return "1";
    string ans = "";
    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);
    solve(ans, v, n, k);
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getPermutation(n, k);
}