#include<iostream>
#include<unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data) {
        next = NULL; prev=NULL;
        this->data = data;
    }
    
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// #include"solution.h"

Node * takeLLInput() {
    Node* head=NULL;
    Node* rear=NULL;
    int data;
    cin >> data;
    while(data!=-1)
    {
        Node* newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            rear=head;
        }
        else
        {
            rear -> next=newnode;
            newnode -> prev=rear;
            rear=rear -> next;
        }
        cin >> data;
    }
    return head;
}

void printLL(Node *  head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 void printAllPairSum(Node *head , int x){
     unordered_set<int> visited;
     while(head){
         if(visited.find( x- (head->data) )!=visited.end()){
             cout<<(x -(head->data))<<" "<<(head->data)<<endl;
         }
         visited.insert(head->data);
         head=head->next;
     }
 }

int main()
{
    //fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* head1 = takeLLInput();
    int x;
    cin>>x;
    printAllPairSum(head1, x);
    
    return 0;
}