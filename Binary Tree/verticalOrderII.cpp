#include<bits/stdc++.h>
#include "Tree.h"
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
using namespace std;
vector<vector<int>> verticalTraversal(Tree<int>* root) {
	vector<vector<int>> output;
	int hd=0;//horizontal distance
	queue<pair<Tree<int>* , int>> pending;//for level order traversing
	pending.push(make_pair(root , hd));//pair of node and their horizontal distance
	map<int, vector<int>> m;
	while(pending.size()){
		int size=pending.size();
		map<int,vector<int>> temp;
		for(int i=0 ; i<size ; i++){
			Tree<int> *curr=pending.front().first;
			hd=pending.front().second;
			pending.pop();
			temp[hd].push_back(curr->data);
			if(curr->left){
				pending.push(make_pair(curr->left , hd-1));
			}
			if(curr->right){
				pending.push(make_pair(curr->right , hd+1));
			}
		}
		for(auto x:temp){
			sort(x.second.begin() , x.second.end());
			for(auto val:x.second)
				m[x.first].push_back(val);
		}
	}
	for(map<int , vector<int>> ::iterator it=m.begin(); it!=m.end() ; it++){
		output.push_back((*it).second);
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