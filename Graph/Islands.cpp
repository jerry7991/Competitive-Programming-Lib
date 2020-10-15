#include <bits/stdc++.h>
#define fon(i,n) for (unsigned int i = 0; i < n; ++i)
#define pb push_back
using namespace std;
int solve(int n , int m,vector<int> u , vector<int> v){
	vector<int> *edge=new vector<int>[n];
	fon(i,m){
		edge[u[i]-1].pb(v[i]-1);
		edge[v[i]-1].pb(u[i]-1);
	}
	queue<int> pending;
	bool *visited=new bool[n];
	fon(i,n)visited[i]=false;
	int nCC=0;//by default 0 connected component for null vertex and null edges
	fon(i , n){
		if(visited[i]) continue;
		nCC++;//one more connected components
		//do bfs
		pending.push(i);
		visited[i]=true;
		while(pending.size()){
			int adjacent=pending.front();
			pending.pop();
			fon(j , edge[adjacent].size()){
				int neighbour=edge[adjacent][j];
				if(visited[neighbour] || neighbour==adjacent) continue;
				//else have to store in queue
				pending.push(neighbour);
				visited[neighbour]=true;
			}
		}
	}
	delete []edge;
	delete []visited;
	return nCC;//number of connected component
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> u;
	fon(i,m){
		int x;cin>>x;
		u.pb(x);
	}
	vector<int> v;
	fon(i,m){
		int x;cin>>x;
	v.pb(x);
	}
	cout<<solve(n,m , u,v);
	return 0;
}