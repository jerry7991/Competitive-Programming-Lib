#include <bits/stdc++.h>
using namespace std;

vector<int> dp(10001, -2);
class Solution {
   public:
    int solve(vector<int>& dist, int speed, double hoursBefore, double totalHr, int i, int skip) {
        if (i == dist.size() || totalHr > hoursBefore) {
            if (totalHr <= hoursBefore) {
                return skip;
            } else {
                return INT_MAX;
            }
        }

        if (dp[i] != -2) return dp[i];

        double afterSkipped = i != dist.size() - 1 ? ceil(totalHr + (double)dist[i] / speed) : (totalHr + (double)dist[i] / speed);

        int first = solve(dist, speed, hoursBefore, totalHr + ((double)dist[i] / speed), i + 1, skip + 1);
        int second = solve(dist, speed, hoursBefore, afterSkipped, i + 1, skip);
        return dp[i] = min(first, second);
    }

    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        // int x= solve(dist, speed, hoursBefore,0.0,0,0);
        // return (x == INT_MAX)?-1:x;
    }
};

int main() {
}