#include <bits/stdc++.h>
using namespace std;

int longestBeautifulSubstring(string word) {
    int n = word.size(), len = 0;

    for (int i = 0, j = 0; i < n; i++) {
        if (word[i] == 'a') {
            int cnt = 0;

            // word[j - 1] <= word[j] Because for make sure that i-j is greater or equal

            for (j = i + 1; j < n && word[j - 1] <= word[j]; j++) {
                if (word[j - 1] < word[j]) {
                    cnt++;
                }
            }

            if (cnt == 4) {
                len = max(len, j - i);
            }
            i = j - 1;
        }
    }

    return len;
}

int main() {
    string str;
    cin >> str;
    cout << longestBeautifulSubstring(str);
}