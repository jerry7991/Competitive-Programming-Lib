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
	queue<Tree<int>*>q;//for storing the node
	q.push(root);
	q.push(NULL);//as dummy node which determine weather we changing the level or not
	int count=1;//by default root is at level 1
	while(q.size()){
		Tree<int>*temp=q.front();q.pop();
		if(!temp){
			count++;
			if(count%2==0){
				if(q.size()){
					q.push(NULL);
					temp=q.front();
					vector<Tree<int>*> node;
					vector<int>data;
					while(temp){
						temp=q.front();q.pop();
						if(temp){
							node.push_back(temp);
							data.push_back(temp->data);
							if(temp->left) q.push(temp->left) ;
							if(temp->right) q.push(temp->right);
						}
					}
					if(q.size()) q.push(NULL);
					count++;
					int x=0;
					//cout<<"\n even position is \n";
					for(int i=data.size()-1 ; i>=0 ; i--,x++)
					{
						Tree<int>*curr=node[x];
						curr->data=data[i];
						//cout<<data[i]<<" , ";
					}
				//	cout<<endl;
				}
			}else{
				if(q.size())  q.push(NULL);
			}
		}else{
			//cout<<temp->data<<" ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
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
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1