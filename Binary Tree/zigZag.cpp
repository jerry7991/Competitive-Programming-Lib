#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;
vector<vector<int>> zigzagLevelOrder(Tree<int>* root) {
 queue<Tree<int>*> level;
 level.push(root);
 level.push(NULL);
 int flag=1;
 stack<int> st;
 queue<int> q;
 vector<vector<int>> output;
 while(level.size()){
 	Tree<int>*temp=level.front();
 	level.pop();
 	vector<int> ans;
 	while(temp){
 		if(flag) q.push(temp->data);
 		else st.push(temp->data);
 		if(temp->left) level.push(temp->left);
 		if(temp->right) level.push(temp->right);
 		temp=level.front();
 		level.pop();
 	}
 	if(level.size()) level.push(NULL);
 	if(flag){
 		while(q.size()){
 			ans.push_back(q.front());
 			q.pop();
 		}
 	}else{
 		while(st.size()){
 			ans.push_back(st.top());
 			st.pop();
 		}
 	}
 	output.push_back(ans);
 	flag^=1;
 }
 return output;
}
int main(){
	Tree<int>*root=takeInput();
	vector<vector<int>> output=zigzagLevelOrder(root);
	for(int i=0; i<output.size();i++){
		for(int j=0 ; j<output[i].size();j++) cout<<output[i][j]<<' ';
	cout<<endl;
	}
}