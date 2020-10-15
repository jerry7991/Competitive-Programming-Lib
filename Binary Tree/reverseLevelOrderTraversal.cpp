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
void reverseLevelOrder(Tree<int> *root){
	vector<int> levelOrder;
	queue<Tree<int>*>q;
	q.push(root);
	while(q.size()){
		Tree<int>*temp=q.front();
		q.pop();
		levelOrder.push_back(temp->data);
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	for(int i=levelOrder.size()-1 ; i>=0 ; i--) cout<<levelOrder[i]<<" ";
}
int main(){
	Tree<int>*root=takeInput();
	reverseLevelOrder(root);
}