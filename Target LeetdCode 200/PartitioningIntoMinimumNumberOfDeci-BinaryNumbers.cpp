#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minPartitions(string n) {
        int m = 0;
        for (char ch : n) {
            m = max(m, ch - '0');
        }
        return m;
    }
};

int main() {
    string n;
    cin >> n;
    cout << (new Solution())->minPartitions(n) << endl;
}
