class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};

        while (res.size() < n) {
            vector<int> temp;
            for (int i : res) if (i * 2 - 1 <= n)temp.push_back(i * 2 - 1);
            for (int i : res) if (i * 2 <= n) temp.push_back(i * 2);
            res = temp;
        }
        return res;
    }
};