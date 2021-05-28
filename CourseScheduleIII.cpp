#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int getLastIndex(vector<vector<int>> &courses, int left, int right, int startTime) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (courses[mid][1] > startTime) {
        return getLastIndex(courses, left, mid - 1, startTime);
    } else if (courses[mid][1] <= startTime && courses[mid + 1][1] <= startTime) {
        return getLastIndex(courses, mid + 1, right, startTime);
    } else {
        return mid;
    }
}

int scheduleCourse(vector<vector<int>> &courses) {
    int n = courses.size();
    sort(courses.begin(), courses.end(), compare);

    multiset<int> cls;  // store lengths of each course we take (could be duplicates!)

    int currsum = 0;
    for (int i = 0; i < n; i++) {
        // If we have enough time then we can take courses
        if (currsum + courses[i][0] <= courses[i][1]) {
            cls.insert(courses[i][0]);
            currsum += courses[i][0];
        } else if (*cls.rbegin() > courses[i][0]) {
            // if we don't have enough time, we switch out a longer course
            currsum += courses[i][0] - *cls.rbegin();
            cls.erase(--cls.end());
            cls.insert(courses[i].front());
        } else {
            // if we don't have enough time for course[i],
            //and it's longer than any courses taken, then we ignore it
        }
    }
    return cls.size();
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> course(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) cin >> course[i][j];
    }
    cout << scheduleCourse(course);
}