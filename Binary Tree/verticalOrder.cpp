#include<bits/stdc++.h>
#include "Tree.h"
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
using namespace std;
void getDepth(Tree<int> *root , int &maxDepth , int &minDepth , int depth){
	if(!root) return;
	maxDepth=max(depth , maxDepth);
	minDepth=min(depth , minDepth);
	getDepth(root->left , maxDepth , minDepth , depth-1);
	getDepth(root->right , maxDepth , minDepth , depth+1);
}
void get_VerticalAt_I(Tree<int> *root , int depth , vector<int> &v , int currDepth){
	if(!root) return;
	if(currDepth==depth){
		v.push_back(root->data);
		//return;
	}
	get_VerticalAt_I(root->left  , depth , v ,currDepth-1);
	get_VerticalAt_I(root->right , depth , v, currDepth+1);
}
vector<vector<int>> verticalTraversal(Tree<int>* root) {
	int maxDepth=INT_MIN,minDepth=INT_MAX;
	getDepth(root ,maxDepth , minDepth , 0);
	cout<<maxDepth<<" "<<minDepth<<'\n';
	vector<vector<int>> output;
	for(int i=minDepth ; i<=maxDepth ; i++){
		vector<int> v;
		get_VerticalAt_I(root , i , v ,0);
		output.push_back(v);
	}
	return output;
}
int main(){
	Tree<int> *root=takeInput();
	vector<vector<int>> output=verticalTraversal(root);
	for(int i=0 ; i<output.size() ; i++){
		for(int j=0 ; j<output[i].size() ; j++) cout<<output[i][j]<<' ';
		cout<<'\n';
	}
return 0;
}