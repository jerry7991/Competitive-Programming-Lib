#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        vector<int> nums(words.size());
        for (int i = 0; i < words.size(); i++) {
            int bit = 0;
            for (int j = 0; j < words[i].size(); j++) {
                bit |= 1 << (words[i][j] - 'a');
            }
            nums[i] = bit;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[i] & nums[j]) == 0) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    cout << (new Solution())->maxProduct(words) << endl;
    return 0;
}