#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode * getRoot(vector<int>& inOrder , vector<int>&postOrder , int sIn , int eIn, int sP , int eP){
     if(sIn>eIn || sP>eP) return nullptr;
	if(sIn==eIn){
		TreeNode *root=new TreeNode(inOrder[sIn]);
		return root;
	}
	int rootData=postOrder[eP];
	int index=-1,len=0;
	for(int i=sIn ; i<=eIn ; i++,len++){
		if(rootData==inOrder[i]){
			index=i;
			break;
		}
	}
	if(index==-1) return nullptr;
	TreeNode *root=new TreeNode(rootData);
	root->left=getRoot(inOrder , postOrder , sIn , index-1 , sP , sP+len-1);
	root->right=getRoot(inOrder , postOrder , index+1 , eIn , sP+len  ,eP-1);
	return root;
}
TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
	return getRoot(inOrder , postOrder , 0 ,inOrder.size()-1 , 0 , postOrder.size()-1);
}
void inorder(TreeNode *root){
	if(!root) return;
	inorder(root->left);
	printf("%d  ",root->val);
	inorder(root->right);
}
int main(){
	int n;
	cin>>n;
	vector<int> inOrder,postOrder;
	for(int i=0 ;i<n ; i++){
		int x;
		cin>>x;
		inOrder.push_back(x);
	}
	for(int i=0 ;i<n ; i++){
		int x;
		cin>>x;
		postOrder.push_back(x);
	}
	TreeNode *root=buildTree(inOrder , postOrder);
	inorder(root);
return 0;
}