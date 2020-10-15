#include <iostream>
#include "Tree.h"
using namespace std;
bool isSameTree(Tree<int>* p, Tree<int>* q) {
    if(!p || !q) return (!p && !q);
    if(p->data != q->data) return false;
    return isSameTree(p->left  , q->left) && isSameTree(p->right , q->right);
}
int main(){
	Tree<int> *root1=takeInput();
	Tree<int> *root2=takeInput();
	cout<<isSameTree(root1 , root2);
}