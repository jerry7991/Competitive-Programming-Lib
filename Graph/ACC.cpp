#include <bits/stdc++.h>
#define fon(i,n) for(unsigned int i=0 ; i<n ; i++)
#define pb push_back
#define cin(x)	unsigned int x;cin>>x;
using namespace std;
void dfs(vector<int>*edge , vector<int>* currPath , bool *visited , int src){
	visited[src]=true;
	currPath->pb(src);
	fon(i,edge[src].size()){
		if(visited[edge[src][i]])	continue;
		dfs(edge , currPath , visited , edge[src][i]);
	}
}
int main(){
	cin(n);cin(m);
	vector<int>*edge=new vector<int>[n];
	fon(i,m){
		cin(src);cin(dest);
		edge[src].pb(dest);
		edge[dest].pb(src);
	}
	vector<	vector<int>*> *connected=new vector< vector<int>*>();
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	fon(i,n){
		if(visited[i]) continue;
		vector<int> *currPath=new vector<int>();
		dfs(edge , currPath , visited,i);
		sort(currPath->begin() , currPath->end());
		connected->pb(currPath);
	}
	fon(i , connected->size()){
		vector<int> * comp=connected->at(i);
		fon(j,comp->size())	printf("%d ",comp->at(j) );
		printf("\n");
		delete comp;
	}
	delete []edge;delete []visited; delete connected;
}