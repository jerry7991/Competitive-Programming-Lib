#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        vector<int> out(2, -1);

        int s = 0;
        for (int i : arr) s += i;
        if (s % 3 != 0) return {-1, -1};
        int t = s / 3;  // (Divide all int into three part)
        if (t == 0) return {0, n - 1};
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            one++;
            if (one == 1) i1 = i;
            if (one == t) j1 = i;
            if (one == t + 1) i2 = i;
            if (one == 2 * t) j2 = i;
            if (one == 2 * t + 1) i3 = i;
            if (one == 3 * t) j3 = i;
        }
        vector<int> part1(arr.begin() + i1, arr.begin() + j1 + 1);
        vector<int> part2(arr.begin() + i2, arr.begin() + j2 + 1);
        vector<int> part3(arr.begin() + i3, arr.begin() + j3 + 1);

        if (part1 != part2 || part1 != part3) return out;
        int x = i2 - j1 - 1;
        int y = i3 - j2 - 1;
        int z = n - j3 - 1;
        if (x < z || y < z) return out;
        return {j1 + z, j2 + z + 1};
    }
};

int main() {
}