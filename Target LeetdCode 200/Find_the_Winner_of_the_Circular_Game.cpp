#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    Node* next;
    int data;
    Node(int data) {
        this->data = data;
    }
};

class Solution {
   public:
    int solve(int k, Node* curr, int len) {
        if (len == 1) {
            return curr->data;
        }
        int x = 1;
        while (x < k - 1) {
            curr = curr->next;
            x++;
        }
        Node* del = curr->next;
        curr->next = del->next;
        delete del;
        return solve(k, curr->next, len - 1);
    }

    int findTheWinner(int n, int k) {
        if (k == 1) return n;
        Node *node = nullptr, *tell = nullptr;
        int i = 1;
        while (i <= n) {
            if (node == nullptr) {
                node = new Node(i);
                tell = node;
            } else {
                tell->next = new Node(i);
                tell = tell->next;
            }
            i++;
        }
        tell->next = node;
        return solve(k, node, n);
    }

    int ans(int n, int k) {
        vector<bool> nums(n, true);
        int i = 0, cnt = n;
        while (cnt > 1) {
            for (int j = 0; j < k; j++, i++) {
                while (!nums[i % n]) i++;
            }
            nums[(i - 1) % n] = false;
        }
        for (i = 0; i < n; i++) {
            if (nums[i]) return i + 1;
        }
        return i + 1;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    cout << (new Solution())->findTheWinner(n, k);
    return 0;
}