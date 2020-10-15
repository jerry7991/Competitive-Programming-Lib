#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;
void printTopView(Tree<int>*root){
	if(!root) return;
	unordered_map<int,int>m;
	queue<pair<Tree<int>*,int>> q;
	q.push(make_pair(root , 0));
	while(q.size()){
		pair<Tree<int>*, int> temp=q.front();
		Tree<int> *topView=temp.first;
		int topViewValue=temp.second;
		q.pop();
		if(m.find(topViewValue)==m.end()){
			m[topViewValue]=topView->data;
			cout<<topView->data<<" ";
		}
		if(topView->left){
			q.push(make_pair(topView->left ,topViewValue-1));
		}
		if(topView->right){
			q.push(make_pair(topView->right , topViewValue+1));
		}
	}
}
int main(){
	Tree<int>*root=takeInput();
	printTopView(root);
}