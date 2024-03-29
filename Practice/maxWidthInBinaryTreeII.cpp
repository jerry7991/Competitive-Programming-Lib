#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
	T val;
	TreeNode<T> *left;
	TreeNode<T> *right;
	TreeNode(T val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
	~TreeNode() {
		if (left != NULL) {
			delete left;
		}
		if (right != NULL) {
			delete right;
		}
	}
};

TreeNode<int> *takeInput() {
	int rootData;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> q;
	q.push(root);
	while (q.empty() == false) {
		TreeNode<int> *curr = q.front();
		q.pop();
		int leftChild, rightChild;
		cin >> leftChild;
		if (leftChild != -1) {
			curr->left = new TreeNode<int>(leftChild);
			q.push(curr->left);
		}
		cin >> rightChild;
		if (rightChild != -1) {
			curr->right = new TreeNode<int>(rightChild);
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
	return 1+max(leftHeight,rightHeight);
}
void applyPreorder(TreeNode<int> *root , int *nodesAtLevel , int level){
	if(root==NULL){
		return ;
	}
	nodesAtLevel[level]++;
	applyPreorder(root->left , nodesAtLevel , level+1);
	applyPreorder(root->right, nodesAtLevel , level+1);
}
int maxWidth(TreeNode<int> *root) {
	int ht=height(root);
	int *nodesAtLevel=new int[ht];
	for(int i=0;i<ht;i++) nodesAtLevel[i]=0;
	applyPreorder(root , nodesAtLevel , 0);
	
	int ans=0;
	for(int i=0 ; i<ht ; i++){
		ans=max(ans , nodesAtLevel[i]);
	}
	delete []nodesAtLevel;
	return ans;
}

int main() {
	TreeNode<int> *root = takeInput();
	// print(root);
	cout << maxWidth(root);
	return 0;
}