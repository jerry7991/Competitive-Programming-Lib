#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
    vector<int> arr;
    int maxVal = 0;
    while (num) {
        arr.push_back(num % 10);
        maxVal = max(maxVal, num % 10);
        num /= 10;
    }
    reverse(arr.begin(), arr.end());
    int i = 0;

    // Find sloping point
    while (i < arr.size() - 1 && arr[i] > arr[i + 1]) i++;
    if (i != arr.size() - 1) {
        int maxValue = arr[i], j = i + 1, id = i;
        while (j < arr.size()) {
            if (maxVal < arr[j]) {
                maxVal = arr[j];
                id = j;
            }
            j++;
        }
        swap(arr[i], arr[id]);
    }
    for (int i = 0; i < arr.size(); i++) num = num * 10 + arr[i];
    return num;
}

int main() {
    int n;
    cin >> n;
    cout << maximumSwap(n);
}