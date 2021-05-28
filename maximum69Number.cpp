#include <bits/stdc++.h>
using namespace std;
    
int maximum69Number(int num) {
    vector<int> n;
    while (num) {
        n.push_back(num % 10);
        num /= 10;
    }
    for (int i = 0, j = n.size() - 1; i < j; i++, j--) swap(n[i], n[j]);
    bool flag = true;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == 6 && flag) {
            n[i] = 9;
            flag = false;
        }
        num = num * 10 + n[i];
    }
    return num;
}
int main() {
    int n;
    cin >> n;
    cout << maximum69Number(n);
}