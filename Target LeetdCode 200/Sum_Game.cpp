#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool sumGame(string num) {
        int diff = 0, n = num.size();
        for (int i = 0; i < n; i++) {
            int f = 2 * (num[i] - '0');
            if (num[i] == '?') f = 9;
            if (i < n / 2)
                diff += f;
            else
                diff -= f;
        }
        return diff != 0;
    }
};

int main() {
    string s;
    cin >> s;
    cout << (new Solution())->sumGame(s);
}