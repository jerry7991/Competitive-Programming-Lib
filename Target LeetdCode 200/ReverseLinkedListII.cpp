#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> st;
        ListNode *temp = head, *tmp = nullptr;
        for (int i = 1; i != left; i++) temp = temp->next;
        tmp = temp;
        for (int i = left; i != right; i++) st.push(temp->val), temp = temp->next;
        while (st.size()) {
            tmp->val = st.top();
            st.pop();
            tmp = tmp->next;
        }
        return head;
    }
};

int main() {
}