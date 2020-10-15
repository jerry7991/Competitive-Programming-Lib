#include <iostream>
#include <stack>
using namespace std;
class MinStack {
   private:
    stack<int> original, minStack;

   public:
    MinStack() {
    }

    void push(int x) {
        original.push(x);
        if (minStack.size() == 0 || minStack.top() >= x) {
            minStack.push(x);
        }
    }

    void pop() {
        if (minStack.size() != 0 && original.size() != 0 && minStack.top() == original.top()) {
            minStack.pop();
        }
        original.pop();
    }

    int top() {
        return original.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack *ms = new MinStack();
    while (true) {
        int ch, val;
        cin >> ch;
        if (ch == 1) {
            cin >> val;
            ms->push(val);
        } else if (ch == 2) {
            ms->pop();
        } else if (ch == 3) {
            cout << ms->getMin() << endl;
        } else if (ch == 4) {
            cout << ms->top() << endl;
        } else {
            break;
        }
    }
    return 0;
}