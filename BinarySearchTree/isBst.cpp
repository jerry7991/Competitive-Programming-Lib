#include <bits/stdc++.h>
#include "Tree.h"
#define posInfinite 2147483649 
#define negInfinite -2147483649
using namespace std;
inline long findMin(Tree<int> *root){
	if(!root) return posInfinite;
	return min(findMin(root->left) ,min( findMin(root->right) ,(long) root->data));
}
inline long findMax(Tree<int>* root){
	if(!root) return INT_MIN;
	return max(findMax(root->left) ,max( findMax(root->right) ,(long) root->data));
}
bool isBst(Tree<int>*root){
	if(!root) return true;
	long leftMax=findMax(root->left);
	long rightMin=findMin(root->right);
	//cout<<root->data<<"->"<<leftMax<<" , "<<rightMin<<endl;
	return(root->data > leftMax && root->data<rightMin && isBst(root->left) && isBst(root->right));
}
int main(){
	Tree<int>*root=takeInput();

	cout<<isBst(root);
}
/*
inline long findMin(TreeNode *root){
if(!root) return posInfinite;
return min(findMin(root->left) ,min( findMin(root->right) ,(long) root->data));
}
inline long findMax(TreeNode *root){
if(!root) return negInfinite;
return max(findMax(root->left) ,max( findMax(root->right) ,(long) root->data));
}
public:
bool isValidBST(TreeNode* root) {
if(!root) return true;
long leftMax=findMax(root->left);
long rightMin=findMin(root->right);
//cout<<root->data<<"->"<<leftMax<<" , "<<rightMin<<endl;
return(root->data > leftMax && root->data<rightMin && isValidBST(root->left) && isValidBST(root->right));
}
*/