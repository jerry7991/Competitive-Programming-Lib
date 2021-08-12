class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> f0(n + 1, 0), f1(n + 1, 0);

        for (int i = 1, j = n - 1; j >= 0; i++, j--) {
            //  cast to make all left side of 1 to 0
            f0[i] += f0[i - 1] + (s[i - 1] == '0' ? 0 : 1);
            f1[j] += f1[j + 1] + (s[j] == '0' ? 1 : 0);
        }

        int res = INT_MAX;
        for (int i = 0; i <= n; i++) {
            res = min(res, f0[i] + f1[i]);
        }
        return res;
    }
};