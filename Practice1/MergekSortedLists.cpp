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

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> minPq;

    int k = lists.size();
    for (int i = 0; i < k; i++) {
        minPq.push({lists[i]->val, lists[i]});
    }

    ListNode *head = nullptr, *tell = nullptr;

    while (minPq.size()) {
        ListNode *temp = minPq.top().second;
        minPq.pop();
        if (head == nullptr) {
            head = new ListNode(temp->val);
            tell = head;
        } else {
            tell->next = new ListNode(temp->val);
            tell = tell->next;
        }
        if (temp->next) {
            minPq.push({temp->next->val, temp->next});
        }
    }
    return head;
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