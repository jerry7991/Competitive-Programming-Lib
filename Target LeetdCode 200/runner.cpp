#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (next)
        {
            delete next;
        }
    }
};

#include "solution.h"

class Runner
{
    int t;
    vector<Node*> arr1;
    vector<Node*> arr2;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int data;
            cin >> data;
            Node *head = NULL, *tail = NULL;
            while (data != -1)
            {
                Node *newNode = new Node(data);
                if (head == NULL)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
                cin >> data;
            }

            arr1.push_back(head);

            cin >> data;
            head = NULL;
            tail = NULL;
            while (data != -1)
            {
                Node *newNode = new Node(data);
                if (head == NULL)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
                cin >> data;
            }

            arr2.push_back(head);

        }
    }

    void printList(Node *head)
    {
        Node *tail = head;

        while (tail != NULL && tail->next != head)
        {
            cout << tail->data << ' ';
            tail = tail->next;
        }

        if (tail != NULL)
            cout << tail->data << ' ';
        cout << "-1" << endl;
    }

    Node *copyLinkedList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *newLinkedList = new Node(head->data);
        Node *cur = newLinkedList;
        head = head->next;
        while (head != NULL)
        {
            cur->next = new Node(head->data);
            cur = cur->next;
            head = head->next;
        }
        return newLinkedList;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            Node *head1 = copyLinkedList(arr1[i]);
            Node *head2 = copyLinkedList(arr2[i]);
            Node *head = addLL(head1, head2);

            Node *prev1 = head1;
            Node *prev2 = head2;

            while (prev1 != NULL)
            {
                Node*temp = prev1->next;
                prev1->next = NULL;
                delete prev1;
                prev1 = temp;

            }

            while (prev2 != NULL)
            {
                Node*temp = prev2->next;
                prev2->next = NULL;
                delete prev2;
                prev2 = temp;

            }

        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            Node *head1 = copyLinkedList(arr1[i]);
            Node *head2 = copyLinkedList(arr2[i]);
            Node *head = addLL(head1, head2);
            printList(head);
            Node *prev1 = head;
            while (prev1 != NULL)
            {
                Node*temp = prev1->next;
                prev1->next = NULL;
                delete prev1;
                prev1 = temp;

            }
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}