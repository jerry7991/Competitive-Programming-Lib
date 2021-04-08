#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    vector<int> v;

   public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (v.size() == 0)
            v.push_back(num);
        else
            v.insert(lower_bound(v.begin(), v.end(), num), num);
    }

    double findMedian() {
        // sort(v.begin(), v.end());
        int n = v.size();
        if ((n & 1)) {
            return v[n / 2];
        } else {
            return ((double)(v[(n + 1) / 2] + v[(n - 1) / 2])) / 2;
        }
    }
};
