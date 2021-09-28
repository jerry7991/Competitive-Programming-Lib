#include <iostream>
#include <math.h>
#include <queue>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
template <typename T>

class Node {
  public:
    T data;
    Node<T> *next;
    Node<T> *child;

    Node(T data) {
        this->data = data;
        next = NULL;
        child = NULL;
    }
};

using namespace std;
#include "solution.h"

Node<int> *takeinput() {
    int headData;

    cin >> headData;

    if (headData == -1) {
        return NULL;
    }

    Node<int> *head = new Node<int> (headData);
    queue<Node<int> *> q;
    q.push(head);

    while (!q.empty()) {
        Node<int> *currNode = q.front();
        q.pop();
        int left, right;
        cin >> left;

        if (left != -1) {
            Node<int> *leftNode = new Node<int>(left);
            currNode->next = leftNode;
            q.push(leftNode);
        }

        cin >> right;

        if (right != -1) {
            Node<int> *rightNode = new Node<int>(right);
            currNode->child = rightNode;
            q.push(rightNode);
        }

    }
    return head;
}

void printList(Node<int> *head) {
    Node<int> *temp = head;

    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        Node<int> *head = takeinput();
        head = flattenMultiLinkedList(head);
        printList(head);
    }
    return 0;
}