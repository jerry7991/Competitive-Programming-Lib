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
int maxWidth(TreeNode<int> *root) {
	//first find the height of the tree
	if (root == NULL) {
		return 0;
	}
	queue<TreeNode<int>*> q;
	q.push(root);
	int ans=0;
	while(q.empty()==false){
		int count=q.size();
		ans=max(ans , count);
		while(count>0){
			TreeNode<int> *currNode=q.front();
			q.pop();
			if(currNode->left!=NULL){
				q.push(currNode->left);
			}
			if(currNode->right!=NULL){
				q.push(currNode->right);
			}
			count=count-1;
		}
	}
	return ans;
}

int main() {
	TreeNode<int> *root = takeInput();
	// print(root);
	cout << maxWidth(root);
	return 0;
}