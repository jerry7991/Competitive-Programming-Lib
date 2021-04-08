#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n = barcodes.size(), pos = 0;
    unordered_map<int, int> ump;
    for (int i : barcodes) {
        ump[i]++;
    }
    vector<int> out(n);
    set<pair<int, int>> st;
    for (auto it = begin(ump); it != end(ump); it++) st.insert({it->second, it->first});

    for (auto it = begin(st); it != end(st); it++) {
        for (auto count = 0; count < it->first; it++, pos += 2) {
            if (pos >= n) {
                pos = 1;
            }
            out[pos] = it->second;
        }
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> out = rearrangeBarcodes(v);
    for (int i : out) cout << i << " ";
}