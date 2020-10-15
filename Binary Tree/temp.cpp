#include <bits/stdc++.h>
using namespace std;
template <typename T> class Tree{
	public:
	T data;
	Tree<T> *left;
	Tree<T> *right;
	Tree(T data){
		this->data=data;
	}
};
Tree<int>* takeInput(){
	queue<Tree<int>*> q;
	int data;
	cin>>data;
	if(data==-1) return NULL;
	Tree<int> *root=new Tree<int>(data);
	q.push(root);
	while(q.size()){
		Tree<int> *temp=q.front();q.pop();
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
void solve(Tree<int>*root){
	queue<Tree<int>*>q;
	q.push(root);
	q.push(NULL);
	int count=1;
	while(q.size()){
		if(count%2==0){
			vector<Tree<int>*> node;
			vector<int> data;
			Tree<int> *temp=q.front();
			if(!temp){
				if(q.size()==0) break;
				q.pop();
				temp=q.front();
			}
			while(temp){
				temp=q.front();q.pop();
				if(temp) data.push_back(temp->data) , node.push_back(temp),cout<<temp->data<<" ";
				if(temp){
					if(temp->left) q.push(temp->left);
					if(temp->right) q.push(temp->right);
				}
			}
			if(q.size())	q.push(NULL);
			for(int i=data.size() ; i>=0 ; i--){
				node[i]->data=data[i];
			}
		}else{
			Tree<int>*temp=q.front();
			q.pop();
			if(!temp){
				if(q.size()){
					q.push(NULL);
				}
			}else{
				cout<<temp->data<<" ";
				if(temp->left) q.push(temp->left);
				if(temp->right) q.push(temp->right);
			}
		}
		count++;
	}
}
void printInorder(Tree<int> *root){
	if(!root) return;
	printInorder(root->left);
	cout<<root->data<<' ';
	printInorder(root->right);
}
int main(){
	Tree<int>*root=takeInput();
	printInorder(root);
			cout<<" "<<'\n';
	solve(root);
	printInorder(root);
}