#include<bits/stdc++.h>
#include "Tree.h"
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
void fill_map(Tree<int>*root , int hd , int height , map<int,vector<pair<int,int>>> &_map){
	if(!root) return;
	_map[hd].push_back(make_pair(root->data , height));
	fill_map(root->left , hd-1 , height+1 , _map);
	fill_map(root->right , hd+1 , height+1 , _map);
}
bool compare(pair<int,int> p1  , pair<int,int> p2)
{
	if(p1.second==p2.second) return p1.first<p2.first;
	return p1.second<p2.second;
}
vector<vector<int>> verticalTraversal(Tree<int>* root) {
	vector<vector<int>> output;
	map<int, vector<pair<int,int>>> _map;
	fill_map(root ,  0 , 0, _map);
	for( map<int , vector<pair<int,int>>> ::iterator it=_map.begin() ; it!=_map.end() ; it++){
		sort(((*it).second).begin() , ((*it).second).end() , compare);
		vector<int> v;
		for(int i=0 ; i<((*it).second).size() ; i++) v.push_back(((*it).second)[i].first);
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