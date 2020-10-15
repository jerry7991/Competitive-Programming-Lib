#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;
vector<int> getPair(TreeNode  *root , int distance ,int &ans){
	if(!root) return {0};
	if(!root->left && !root->right) return {1};
	vector<int>	leftDistances=getPair(root->left , distance , ans);
	vector<int>	rightDistances=getPair(root->right ,distance ,ans);
	vector<int> currDistances;
	for(auto a:leftDistances){
		for(auto b:rightDistances){
			if((a && b) && a+b<=distance) ans++;
		}
      if(a && a+1<distance) currDistances.push_back(a+1);
	}
  for(auto b:rightDistances) {
    if(b && b+1<distance) currDistances.push_back(b+1);
  }
	return currDistances;
}
public:
    int countPairs(TreeNode* root, int distance) {
	int ans=0;
	vector<int> nCount=getPair(root , distance,ans);
	return ans;
    }
int countPairs(Tree<int>* root, int distance) {
	int ans=0;
	vector<int> nCount=getPair(root , distance,ans);
	return ans;
}
int main(){
	Tree<int>* root=takeInput();
	int distance;
	cin>>distance;
	cout<<countPairs(root,distance)<<'\n';
return 0;
}
/*
1 2 3 5 4  6 7 8 9 10 11 -1 -1 12 13 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
7
*/