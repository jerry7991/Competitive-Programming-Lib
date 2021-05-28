#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(long long num) {
    vector<int> v;
    while (num) {
        v.push_back(num % 10);
        num /= 10;
    }
    int left = 0, right = v.size() - 1;
    while (left < right) {
        if (v[left] != v[right]) return false;
        left++;
        right--;
    }
    return true;
}

int superpalindromesInRange(string left, string right) {
    long long l = stoll(left);
    long long r = stoll(right);
    int magic = 1e5;
    int ans = 0;

    // Count event length
    for (int i = 1; i <= magic; i++) {
        string st = to_string(i);
        for (int j = st.size() - 2; j >= 0; j--) {
            st.push_back(st[j]);
        }
        if (st.size() > right.size()) break;
        long long int v = stoll(st);
        if (v > sqrt(r)) break;
        v *= v;
        if (v > r) break;
        if (v >= l && isPalindrom(v)) {
            ans++;
        }
    }

    //  Count odd length
    for (int i = 1; i <= magic; i++) {
        string st = to_string(i);
        for (int j = st.size() - 1; j >= 0; j--) {
            st.push_back(st[j]);
        }
        long long v = stoll(st);
        if (v > sqrt(r)) break;
        v *= v;
        if (v > r) break;
        if (v >= l && isPalindrom(v)) {
            ans++;
        }
    }

    return ans;
}

int main() {
    string left, right;
    cin >> left >> right;
    cout << superpalindromesInRange(left, right);
}