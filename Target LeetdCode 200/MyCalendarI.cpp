#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
   public:
    vector<pair<int, int>> event;

    MyCalendar() {
    }

    bool book(int start, int end) {
        if (isConflict(start, end)) {
            return false;
        }
        event.push_back({start, end});
        sort(event.begin(), event.end());
    }

    bool isConflict(int s, int e) {
        for (int i = 0; i < event.size(); i++) {
            if ((event[i].first <= e && event[i].second > s)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    MyCalendar* obj = new MyCalendar();
    int t;
    cin >> t;
    while (t--) {
        int start, end;
        cin >> start >> end;
        bool param_1 = obj->book(start, end);
        cout << param_1 << endl;
    }
}
