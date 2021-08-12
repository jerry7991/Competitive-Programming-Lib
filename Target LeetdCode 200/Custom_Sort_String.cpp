#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string customSortString(string order, string str) {
        vector<int> fre(26, 0);
        for (char ch : str) fre[ch - 'a']++;
        string out = "";
        for (char ch : order) {
            while (fre[ch - 'a'] > 0) {
                out.push_back(ch);
                fre[ch - 'a']--;
            }
        }
        for (int i = 0; i < 26, i++) {
            while (fre[i] > 0) {
                out.push_back((char)('a' + i));
                fre[i]--;
            }
        }
        return out;
    }
};

int main() {
    string order, str;
    cin >> order >> str;
    cout << (new Solution())->customSortString(order, str);
}