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
void printInorder(Tree<int> *root , vector<int> &v){
	if(!root) return;
	printInorder(root->left,v);
	v.push_back(root->data);
	printInorder(root->right,v);
}
void solve(vector<int> &v){
	int n=v.size();
	int swapTill=(n+1)/2;
	int powerOf2=2,i=swapTill-1;
	while((i--)>=0){
				
		if(i==(swapTill-powerOf2-1)){
			powerOf2=powerOf2+powerOf2*2;
			continue;
		}
		//else swap
		int temp=v[i];
		v[i]=v[n-i-1];
		v[n-i-1]=temp;
	}
	for(int i=0 ; i<v.size() ; i++) cout<<v[i]<<" ";
}
int main(){
	Tree<int>*root=takeInput();
	vector<int> v;
	printInorder(root , v);
	for(int i=0 ; i<v.size() ; i++)cout<<v[i]<<" ";
	cout<<endl;
	solve(v);
}