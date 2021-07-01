#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxArea(int height, int width, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        if (h.back() != height) h.push_back(height);
        if (v.back() != width) v.push_back(width);
        int maxDifH = 0, maxDifW = 0;
        for (int i = 0; i < h.size(); i++) {
            maxDifH = max(maxDifH, h[i] - i ? h[i - 1] : 0);
        }
        for (int i = 0; i < v.size(); i++) {
            maxDifW = max(maxDifW, v[i] - i ? v[i - 1] : 0);
        }
        return ((long)maxDifH * maxDifW) % 1000000007;
    }
};

int main() {
}