#include <iostream>
#include <queue>
using namespace std;
class RecentCounter {
   private:
    queue<int> call;

   public:
    RecentCounter() {
    }

    int ping(int t) {
        while (call.size() != 0 && call.front() < (t - 3000)) {
            call.pop();
        }
        call.push(t);
        return call.size();
    }
};
int main() {
    int n;
    cin >> n;
    RecentCounter *rc = new RecentCounter();
    while (n != 0) {
        cout << rc->ping(n);
        cin >> n;
    }
}