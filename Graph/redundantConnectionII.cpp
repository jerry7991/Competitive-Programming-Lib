#include<bits/stdc++.h>
using namespace std;
inline int getParent(int u , int *parent){
	if(parent[u]==u) return u;
	return getParent(parent[u] ,parent);
}
vector<int> findRedundantConnection(vector<vector<int>>&edges){
	int n=edges.size();
	int *indegree=new int[n+1];
	vector<int> res;
	int *parent=new int[edges.size()+1];
	queue<pair<int,int>> q;
	for(int i=0 ; i<=n ; i++) parent[i]=i , indegree[i]=0;
	for(int i=0 ; i<n ; i++){
		indegree[edges[i][1]]++;//increament the number of incoming edges
	}
	//if indegree of nodes>2 that's means nodes has two parent
	for(int i=0 ; i<n ; i++){
		//if we are visiting the node which has two parent we don't consider them initially
		if(indegree[edges[i][1]]>1){
			q.push(make_pair(edges[i][0] , edges[i][1]));
		}else{
			int u=edges[i][0];
			int v=edges[i][1];
			int uParent=getParent(u  , parent);
			int vParent=getParent(v  , parent);
			if(uParent==vParent){
				res.push_back(u);
				res.push_back(v);
				continue;
			}
			parent[vParent]=uParent;
		}
	}
	vector<int> newRes;
	//now trying connecting the node in q;
	while(q.size()){
		pair<int,int>curr=q.front();
		q.pop();
		int u=curr.first;
		int v=curr.second;
		int uParent=getParent(u , parent);
		int vParent=getParent(v , parent);
		if(uParent==vParent){
			newRes.push_back(u);
			newRes.push_back(v);
		}
	}
	if(newRes.size()) return newRes;
	return res;
}
int main(){
	vector<vector<int>> v;
	int e;
	cin>>e;
	for(int i=0 ; i<e ; i++){
		vector<int> x;
		int y,z;cin>>y>>z;
		x.push_back(y);
		x.push_back(z);
		v.push_back(x);
	}
	vector<int> output=findRedundantConnection(v);
	cout<<output[0]<<" "<<output[1]<<'\n';
}