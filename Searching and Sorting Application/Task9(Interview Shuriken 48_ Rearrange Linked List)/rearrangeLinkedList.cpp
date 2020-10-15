#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node* rearrangeLinkedList(Node* head){
    //write your code here
    return NULL;
}
int main()
{
    Node _list=new Node;
    cout<<"Enter list element use -1 for null \n";
    while(true)
    {
        int _data;
        cin>>_data;
        if(_data==-1)
            break;
        else
        _list=new Node(_data);
    }
}
