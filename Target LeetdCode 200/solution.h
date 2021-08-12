/*
    Time Complexity: O(N + M)
    Space Complexity: O(max(N,M))

    Where N and M are the number of nodes in the first and the second linked list respectively.

*/

// Reverses the linked list
Node *reverse(Node *head) {
    Node *prev  = NULL;
    Node *curr = head;

    while (curr != NULL) {

        Node *ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;

    }

    return prev;
}

Node *addLL(Node *head1, Node *head2) {


    // If first linked list is empty return second
    if (head1 == NULL) {
        return head2;
    }

    // If second linked list is empty return first
    if (head2 == NULL) {
        return head1;
    }

    // Removing leading zeros from first list
    while (head1 != NULL && head1->data == 0) {

        head1 = head1->next;

    }

    // Removing leading zeros from second list
    while (head2 != NULL && head2->data == 0) {

        head2 = head2->next;

    }

    // If both the lists contains only zeros
    if (head1 == NULL && head2 == NULL) {
        Node *temp = new Node(0);
        return temp;
    }

    // If first list contains only zeros
    if (head1 == NULL) {
        return head2;
    }

    // If second list contains only zeros
    if (head2 == NULL) {
        return head1;
    }

    // Reverse both the linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *ans = NULL;
    Node *traverse;
    int carry = 0;

    // Add the linked lits
    while (head1 != NULL && head2 != NULL) {

        Node *temp = new Node(0);
        int sum = head1->data + head2->data + carry;
        carry = sum / 10;
        sum = sum % 10;
        temp->data = sum;

        if (ans == NULL) {
            ans = temp;
            traverse = temp;
        }
        else {
            traverse->next = temp;
            traverse = traverse->next;
        }

        head1 = head1->next;
        head2 = head2->next;

    }

    // Add the remaining linked list and the carry
    if (head1 != NULL) {

        while (head1 != NULL) {

            Node *temp = new Node(0);
            int sum = head1->data + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->data = sum;
            traverse->next = temp;
            traverse = traverse->next;
            head1 = head1->next;

        }

    }

    if (head2 != NULL) {

        while (head2 != NULL) {

            Node *temp = new Node(0);
            int sum = head2->data + carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->data = sum;
            traverse->next = temp;
            traverse = traverse->next;
            head2 = head2->next;

        }

    }

    if (carry != 0) {

        Node *temp = new Node(0);
        temp->data = carry;
        traverse->next = temp;

    }

    ans = reverse(ans);

    return ans;


}