#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
        // base case
        if (n1.size() * 6 < n2.size() || n2.size() * 6 < n1.size()) return -1;
        int count = 0, sum1 = 0, sum2 = 0;
        sum1 = accumulate(begin(n1), end(n1), 0);
        sum2 = accumulate(begin(n2), end(n2), 0);

        // Let's make n1 as small and n2 as greater
        if (sum1 > sum2) {
            swap(n1, n2);
        }

        priority_queue<int, vector<int>, greater<int>> minPq(begin(n1), end(n1));
        priority_queue<int> maxPq(begin(n2), end(n2));
        int diff = abs(sum1 - sum2);

        while (diff > 0) {
            count++;
            if (minPq.empty() || (!maxPq.empty() && (maxPq.top() - 1 > 6 - minPq.top()))) {
                diff -= (maxPq.top() - 1);
                maxPq.pop();
            } else {
                diff -= (6 - minPq.top());
                minPq.pop();
            }
        }
        return count;
    }
};

int main() {
    int n, v;
    cin >> n >> v;
    vector<int> n1(n), v1(v);
    for (int i = 0; i < n; i++) cin >> n1[i];
    for (int i = 0; i < v; i++) cin >> v1[i];
    cout << (new Solution())->minOperations(n1, v1);
}