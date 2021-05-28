#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s) {
    int left = 0, right = s.size() - 1, n = s.size();
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (left < right) {
        while (left < right && !vowel.count(s[left])) left++;
        while (right > left && !vowel.count(s[right])) right--;
        swap(s[left], s[right]);
        left++;
         right--;
    }
    return s;
}

int main() {
    string str;
    cin >> str;
    cout << reverseVowels(str);
}