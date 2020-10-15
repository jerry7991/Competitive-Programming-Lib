#include <bits/stdc++.h>
#include "Tree.h"
#define posInfinite 2147483649 
#define negInfinite -2147483649
using namespace std;
bool isBst(Tree<int>*root , long long minV=negInfinite , long long maxV=posInfinite){
	if(!root) return true;
	if(((long long)root->data)>=maxV) return false;
	if(((long long)root->data)<=minV) return false;
	bool leftAns= isBst(root->left , minV ,min(maxV , ((long long) root->data)));
	bool rightAns=isBst(root->right , max((long long)root->data , minV) , maxV);
	return leftAns && rightAns;
}
int main(){
	Tree<int>*root=takeInput();

	cout<<isBst(root);
}
/*
#define posInfinite 2147483649 
#define negInfinite -2147483649
#define data val
class Solution {
public:
    bool isValidBST(TreeNode* root, long long minV=negInfinite , long long maxV=posInfinite) {
        if(!root) return true;
        if(((long long)root->data)>=maxV) return false;
        if(((long long)root->data)<=minV) return false;
        bool leftAns= isValidBST(root->left , minV ,min(maxV , ((long long) root->data)));
        bool rightAns=isValidBST(root->right , max((long long)root->data , minV) , maxV);
        return leftAns && rightAns;
    }
};
*/