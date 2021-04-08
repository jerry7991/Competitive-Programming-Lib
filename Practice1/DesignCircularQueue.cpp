#include <bits/stdc++.h>
using namespace std;
class MyCircularQueue {
    vector<int> q;
    int n, front, rear, len;

   public:
    MyCircularQueue(int k) {
        n = k;
        q.resize(n);
        front = 0;
        rear = -1;
        len = 0;
    }

    bool enQueue(int value) {
        if (!isFull()) {
            rear = (rear + 1) % n;
            q[rear] = value;
            len++;
            return true;
        }

        return false;
    }

    bool deQueue() {
        if (!isEmpty()) {
            front = (front + 1) % n;
            len--;
            return true;
        }
        return false;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return q[front];
        }
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return q[rear];
        }
    }

    bool isEmpty() {
        return len == 0;
    }

    bool isFull() {
        return n == len;
    }
};

int main() {
}