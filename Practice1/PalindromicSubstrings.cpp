#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans++;
        int left = i - 1, right = i + 1, x = 0;

        // odd length of palindrome
        while (left >= 0 && right < n) {
            if (s[left] != s[right]) break;
            ans++;
            left--;
            right++;
        }

        if (i > 0 && s[i] == s[i - 1]) {
            left = i - 1, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                ans++;
            }
        }
    }
    return ans;
}

// Using dp
int countSubstringsDP(string s) {
    int n = s.length(), ans = 0;
    if (n == 0) return ans;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Single length will be always palindrome
    for (int i = 0; i < n; i++, ans++) dp[i][i] = true;

    // Double length will be palindrom if and only if there adjacent is same
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        ans += (dp[i][i + 1]);
    }

    // Explore for more than 3 length len[3,n]
    for (int len = 3; len <= n; len++) {
        //  Last is used take the size of subString
        for (int i = 0, last = i + len - 1; i < n && last < n; i++, last++) {
            dp[i][last] = dp[i + 1][last - 1] && (s[i] == s[last]);

            ans += (dp[i][last]);
        }
    }
    return ans;
}

int countSubstringsTrivil(string s) {
    int n = s.length();
    vector<int> odd(n), even(n);

    for (int i = 0; i < n; i++) {
        odd[i] = 1;

        while ((i - odd[i]) >= 0 && (i + odd[i]) < n && s[i - odd[i]] == s[i + odd[i]]) {
            odd[i]++;
        }

        even[i] = 0;
        while ((i - even[i] - 1) >= 0 && (i + even[i]) < n && s[i - even[i] - 1] == s[i + even[i]]) {
            even[i]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += odd[i] + even[i];
    return ans;
}

int countSubstringsManacherS(string s) {
    int n = s.length(), i, l, r;
    vector<int> odd(n), even(n);

    // Single For odd
    for (i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[r + l - i], r - i + 1);
        while (0 <= (i - k) && (i + k < n) && s[i - k] == s[i + k]) {
            k++;
        }

        odd[i] = k--;

        if (l + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    // For even length
    for (i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
        while (0 <= (i - k - 1) && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }

        even[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
}

int main() {
    string str;
    cin >> str;
    cout << countSubstrings(str);
}