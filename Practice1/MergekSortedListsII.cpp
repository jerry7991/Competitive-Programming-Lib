#include <iostream>
#include <queue>
#include <vector>
#define nullptr NULL

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *takeInput() {
    ListNode *head = nullptr, *tell = nullptr;
    int data;
    cin >> data;
    while (data != -1) {
        if (head == nullptr) {
            head = new ListNode(data);
            tell = head;
        } else {
            tell->next = new ListNode(data);
            tell = tell->next;
        }
        cin >> data;
    }
    return head;
}

ListNode *mergeTwoLists(ListNode *first, ListNode *second) {
    ListNode *dummy = new ListNode(-1);
    ListNode *tell = dummy;

    while (first && second) {
        if (first->val < second->val) {
            tell->next = new ListNode(first->val);
            first = first->next;
        } else {
            tell->next = new ListNode(second->val);
            second = second->next;
        }
        tell = tell->next;
    }

    if (!first) {
        tell->next = second;
    }
    if (!second) {
        tell->next = first;
    }
    return dummy->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int interval = 1;

    while (interval < lists.size()) {
        for (int i = 0; (i + interval) < lists.size(); i = (i + interval * 2)) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
}

int main() {
    int k;
    cin >> k;
    vector<ListNode *> lists(k);
    for (int i = 0; i < k; i++) {
        lists[i] = takeInput();
    }

    ListNode *head = mergeKLists(lists);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}