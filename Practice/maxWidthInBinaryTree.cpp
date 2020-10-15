#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode{
public:
	T val;
	TreeNode<T> *left;
	TreeNode<T> *right;
	TreeNode(T val){
		this->val=val;
		left=NULL;
		right=NULL;
	}
	~TreeNode(){
		if(left!=NULL){
			delete left;
		}
		if(right!=NULL){
			delete right;
		}
	}
};

TreeNode<int> *takeInput(){
	int rootData;
	cin>>rootData;
	if(rootData==-1){
		return NULL;
	}
	TreeNode<int> *root=new TreeNode<int>(rootData);
	queue<TreeNode<int>*> q;
	q.push(root);
	while(q.empty()==false){
		TreeNode<int> *curr=q.front();
		q.pop();
		int leftChild,rightChild;
		cin>>leftChild;
		if(leftChild!=-1){
			curr->left=new TreeNode<int>(leftChild);
			q.push(curr->left);
		}
		cin>>rightChild;
		if(rightChild!=-1){
			curr->right=new TreeNode<int>(rightChild);
			q.push(curr->right);
		}
	}
	return root;
}
int height(TreeNode<int> *root){
	if(root==NULL){
		return 0;
	}
	int leftHeight=height(root->left);
	int rightHeight=height(root->right);
	return 1+max(leftHeight , rightHeight);
}
int getWidthAtLevel(TreeNode<int> *root , int level){
	if(root==NULL){
		return 0;
	}
	if(level==1){
		return 1;
	}
	int leftWidth=getWidthAtLevel(root->left , level-1);
	int rightWidth=getWidthAtLevel(root->right , level-1);
	return (leftWidth+rightWidth);
}
int maxWidth(TreeNode<int> *root) {
	//first find the height of the tree
	int ht=height(root);
	int maxWidth=0,currWidth=0;
	for(int i=1 ; i<=ht ; i++){
		currWidth=getWidthAtLevel(root , i);
		cout<<i<<" "<<currWidth<<endl;
		if(maxWidth<currWidth){
			maxWidth=currWidth;
		}
	}
	return maxWidth;
}

int main(){
	TreeNode<int> *root=takeInput();
	// print(root);
	cout<<maxWidth(root);
	return 0;
}