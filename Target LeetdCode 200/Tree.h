#include <bits/stdc++.h>
using namespace std;
template <typename T> class Tree{
public:
	T data;
	Tree<T> *left;
	Tree<T> *right;
	Tree(T data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};
Tree<int> * takeInput(){
	queue<Tree<int>*> q;
	int data;
	cin>>data;
	if(data==-1) return NULL;
	Tree<int>*root=new Tree<int>(data);
	q.push(root);
	while(q.size()){
		Tree<int> *temp=q.front();
		q.pop();
		cin>>data;
		if(data!=-1){
			temp->left=new Tree<int>(data);
			q.push(temp->left);
		}else{
			temp->left=NULL;
		}
		cin>>data;
		if(data!=-1){
			temp->right=new Tree<int>(data);
			q.push(temp->right);
		}else{
			temp->right=NULL;
		}
	}
	return root;
}
void printPreOrder(Tree<int> root){
	if(!root) return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}
void printInOrder(Tree<int> root){
	if(!root) return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}
void printPostOrder(Tree<int> root){
	if(!root)return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
void printLevelOrder(Tree<int> root){
	queue<Tree<int>> level;
	if(root)level.push(root);
	int n;
	while(n=level.size()){
		while(n--){
			Tree<int> temp = level.front();
			level.pop();
			cout<<temp->data<<" ";
			if(temp->left) level.push(temp->left);
			if(temp->right) level.push(temp->right);
		}
	}
}