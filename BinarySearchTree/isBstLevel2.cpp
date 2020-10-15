#include <bits/stdc++.h>
#include "Tree.h"
#define posInfinite 2147483649 
#define negInfinite -2147483649
using namespace std;
class Ans{
public:
	long long minV;
	long long maxV;
	bool isBst;
	Ans(){
		minV=posInfinite;
		maxV=negInfinite;
		isBst=true;
	}
};
Ans* solve(Tree<int>*root){
	if(!root){
		Ans *ans=new Ans();
		return ans;
	}
	Ans *leftAns=solve(root->left);
	Ans *rightAns=solve(root->right);
	Ans *ans=new Ans();
	ans->isBst=leftAns->isBst && rightAns->isBst;
	ans->minV=min((long long)root->data , min(leftAns->minV , rightAns->minV));
	ans->maxV=max((long long)root->data , max(rightAns->maxV , leftAns->maxV));
	if( (root->data)<=(leftAns->maxV) || (root->data)>=(rightAns->minV)) ans->isBst=false;
	return ans;
}
bool isValidBST(Tree<int> *root){
	Ans *ans=solve(root);
	return ans->isBst;
}
int main(){
	Tree<int> *root=takeInput();
	cout<<isValidBST(root);
}
/*
#define posInfinite 2147483649 
#define negInfinite -2147483649
#define Tree TreeNode
#define data val
using namespace std;
class Ans{
public:
	long long minV;
	long long maxV;
	bool isBst;
	Ans(){
		minV=posInfinite;
		maxV=negInfinite;
		isBst=true;
	}
};
Ans* solve(Tree *root){
	if(!root){
		Ans *ans=new Ans();
		return ans;
	}
	Ans *leftAns=solve(root->left);
	Ans *rightAns=solve(root->right);
	Ans *ans=new Ans();
	ans->isBst=leftAns->isBst && rightAns->isBst;
	ans->minV=min((long long)root->data , min(leftAns->minV , rightAns->minV));
	ans->maxV=max((long long)root->data , max(rightAns->maxV , leftAns->maxV));
	if( (root->data)<=(leftAns->maxV) || (root->data)>=(rightAns->minV)) ans->isBst=false;
	return ans;
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        Ans *ans=solve(root);
	      return ans->isBst;
    }
};
*/