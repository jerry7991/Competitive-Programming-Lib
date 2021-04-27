#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    int rem = 0, sum = 0;
    while (l1 && l2) {
        sum = (l1->val + l2->val + rem);
        temp->next = new ListNode(sum % 10);
        rem = sum / 10;

        l1 = l1->next;
        l2 = l2->next;
        temp = temp->next;
    }

    while (l1) {
        sum = (l1->val + rem);
        temp->next = new ListNode(sum % 10);
        rem = sum / 10;

        temp = temp->next;
        l1 = l1->next;
    }

    while (l2) {
        sum = (l2->val + rem);
        temp->next = new ListNode(sum % 10);
        rem = sum / 10;

        temp = temp->next;
        l2 = l2->next;
    }

    if (rem) {
        temp->next = new ListNode(rem);
        temp = temp->next;
    }

    return dummy->next;
}

int main() {
}