#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> st;
    for (char ch : jewels) st.insert(ch);
    int ans = 0;
    for (char ch : stones) {
        if (st.count(ch)) ans++;
    }
    return ans;
}

int main() {
    string jewels, stones;
    cin >> jewels >> stones;
    cout << numJewelsInStones(jewels, stones);
}