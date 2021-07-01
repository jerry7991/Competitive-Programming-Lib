#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        gray.push_back(0);

        for (int i = 1; i <= n; i++) {
            int x = 1 << (i - 1), gs = gray.size() - 1;
            for (int j = gs; j >= 0; j--) {
                gray.push_back(x + gray[j]);
            }
        }
        return gray;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> gray = (new Solution())->grayCode(n);
    for (int x : gray) cout << x << " ";
    return 0;
}