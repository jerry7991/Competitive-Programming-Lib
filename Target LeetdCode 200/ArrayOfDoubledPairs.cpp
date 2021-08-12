class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> mp;
        for (int i : arr) {
            mp[i]++;
        }

        for (auto x : mp) {
            int i = x.first;
            if (x.second == 0) continue;
            if (i < 0) {
                i /= 2;
            } else {
                i *= 2;
            }

            if (x.first < 0 && x.first % 2) {
                return false;
            }

            if (mp[x.first] > mp[i]) return false;

            mp[i] = mp[i] - mp[x.first];
        }
        return true;
    }
};