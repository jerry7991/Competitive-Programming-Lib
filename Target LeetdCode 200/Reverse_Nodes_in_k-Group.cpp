#include <bits/stdc++.h>

#include "ListNode.h"
using namespace std;
class Solution {
   public:
    ListNode* Reverse(ListNode* head) {
        ListNode *reverse = nullptr, *prev = head, *next = head;
        while (prev != nullptr) {
            next = prev->next;
            prev->next = reverse;
            reverse = prev;
            prev = next;
        }
        return reverse;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* ans = temp;
        while (temp->next) {
            ListNode *first = temp->next, *second = temp->next;
            for (int i = 1; i < k && second; i++) {
                second = second->next;
            }

            ListNode* secondPart = nullptr;
            if (second) {
                secondPart = second->next;
                second->next = nullptr;
            } else {
                // It should remain same
                break;
            }
            temp->next = Reverse(temp->next);
            while (temp->next) temp = temp->next;
            temp->next = secondPart;
        }
        return ans->next;
    }
};
