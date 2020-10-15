#include<bits/stdc++.h>
using namespace std;
inline int findParent(int *parent , int x){
	if(parent[x]==x) return x;
	return findParent(parent ,parent[x]);
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	int n=edges.size();
	vector<int> output;
	if(n==0) return output;
    int *parent=new int[n];
    for(int i=1 ;i<=n ; i++ )parent[i]=i;
    for(int i=0 ; i<n ; i++){
    	int x=edges[i][0];
    	int y=edges[i][1];
    	int parentX=findParent(parent ,x);
    	int parentY=findParent(parent ,y);
    	if(parentX==parentY){
    		output.push_back(x);
    		output.push_back(y);
    		break;
    	}else{
    		parent[parentY]=parentX;
    	}
    }
    delete []parent;
    return output;
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