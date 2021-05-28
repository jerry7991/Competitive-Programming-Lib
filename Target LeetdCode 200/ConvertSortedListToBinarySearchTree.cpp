#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *generateTree(ListNode *head) {
    // In case of null
    if (!head) {
        return NULL;
    }

    //  In case of single
    if (!head->next) {
        return new TreeNode(head->val);
    }

    // Find the mid
    ListNode *slow = head, *fast = head, *prevSlow = NULL;
    while (fast && fast->next) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Create new node
    TreeNode *newNode = new TreeNode(slow->val);

    // Remove the link from left side
    prevSlow->next = NULL;

    newNode->left = generateTree(head);
    newNode->right = generateTree(slow ? slow->next : NULL);
    return newNode;
}

TreeNode *sortedListToBST(ListNode *head) {
    TreeNode *root = generateTree(head);
    return root;
}

ListNode *takeInput() {
    int n;
    ListNode *head = NULL, *tail = NULL;
    cin >> n;
    while (n != -1) {
        if (head == NULL) {
            head = new ListNode(n);
            tail = head;
        } else {
            tail->next = new ListNode(n);
            tail = tail->next;
        }
        cin >> n;
    }
    return head;
}

void print(ListNode *head) {
    if (!head) return;
    cout << head->val << endl;
    print(head->next);
}

int main() {
    ListNode *head = takeInput();
    // print(head);
    TreeNode *root = sortedListToBST(head);
}