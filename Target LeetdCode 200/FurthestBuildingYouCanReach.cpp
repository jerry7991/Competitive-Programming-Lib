#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 1; i < h.size(); i++) {
            int d = h[i] - h[i - 1];
            if (d <= 0) continue;
            bricks -= d;
            pq.push(d);
            if (bricks < 0) {
                --ladders;
                bricks += pq.top();
                pq.pop();
                if (bricks < 0 || ladders < 0) return i - 1;
            }
        }
        return h.size() - 1;
    }
};

int main() {
    int n, b, l;
    cin >> n >> b >> l;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    cout << (new Solution())->furthestBuilding(h, b, l);
}