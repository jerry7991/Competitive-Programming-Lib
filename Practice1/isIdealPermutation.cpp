#include <bits/stdc++.h>
using namespace std;

int getMergeInversion(vector<int> &arr, int start, int mid, int end) {
    vector<int> mArr(end - start + 1);
    int i = start, j = mid + 1;

    int count = 0, k = 0;

    while (i <= mid && j <= end) {
        cout << count << endl;
        if (arr[i] > arr[j]) {
            count += (mid - i + 1);
            mArr[k++] = arr[j++];
        } else {
            mArr[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        mArr[k++] = arr[i++];
    }

    while (j <= end) {
        mArr[k++] = arr[j++];
    }
    for (k = 0; k < (end - start + 1); k++) {
        arr[start + k] = mArr[k];
    }
    return count;
}

int getInversion(vector<int> &arr, int start, int end) {
    while (start < end) {
        int mid = (start + end) / 2;
        int leftInversion = getInversion(arr, start, mid);
        int rightInversion = getInversion(arr, mid + 1, end);
        int mergeInversion = getMergeInversion(arr, start, mid, end);

        return (leftInversion + rightInversion + mergeInversion);
    }
    return 0;
}

bool isIdealPermutation(vector<int> &arr) {
    int n = arr.size();
    int global = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) global++;
    }
    int localInversion = getInversion(arr, 0, n - 1);
    for (int i : arr) cout << i << " ";
    cout << global << " " << localInversion << endl;
    return (global == localInversion);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << isIdealPermutation(v);
}