#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(string &a, int i, int j) {
    while (i <= j) {
        if (a[i] != a[j])
            return false;

        i++;
        j--;
    }
    return true;
}

bool check(string &a, string &b) {
    int i = 0, j = a.size() - 1;
    while (i < j && a[i] == b[j])
        i++, j--;
    return isPalindrom(a, i, j) || isPalindrom(b, i, j);
}

bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << checkPalindromeFormation(a, b);
}