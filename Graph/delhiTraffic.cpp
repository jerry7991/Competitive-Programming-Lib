#include <bits/stdc++.h>
using namespace std;
int getMinUnvisitedVert(long long *totalTimeTill , bool *inMst , int n){
	int minVertex=-1;
	for(int i=0 ; i< n ; i++){
		if(!inMst[i] && ((minVertex<0) || totalTimeTill[minVertex]>totalTimeTill[i])) minVertex=i;
	}
	return minVertex;
}
void solve(int *time  ,int**adjMatrix , int n ,int src , int dest){
	long long *totalTimeTill=new long long[n];
	bool *inMst=new bool[n];
	for(int i=0 ;i<n ; i++) totalTimeTill[i]=1000000000 , inMst[i]=false;
	totalTimeTill[src]=0;
	for(int i= 0 ;i<n ; i++){
		int u=getMinUnvisitedVert(totalTimeTill , inMst , n);
		inMst[u]=true;
        if(u==dest) break;
		for(int v=0 ; v< n ; v++){
			if(adjMatrix[u][v]==0 || inMst[v]) continue;
			long long tTotal=totalTimeTill[u]+adjMatrix[u][v];
			//cout<<tTotal<<'\n';
			if(tTotal%time[v]!=0 && v!=dest){
				tTotal=tTotal+time[v]-(tTotal%time[v]);
			}
			if( tTotal<totalTimeTill[v]){
				totalTimeTill[v]=tTotal;
			}
		}
	}
	 cout<<totalTimeTill[dest];
}
int main(){
	int n,m;
	cin>>n>>m;
	int *time=new int[n];
	for(int i=0 ; i<n; i++) cin>>*(time+i);
	int **adjMatrix=new int*[n];
	for(int i=0 ; i<n ; i++){
		adjMatrix[i]=new int[n];
		for(int j=0 ; j<n ; j++) adjMatrix[i][j]=0;
	}
	for(int i=0 ; i<m ; i++){
		int x,y,t;
		cin>>x>>y>>t;
		adjMatrix[x-1][y-1]=t;
		adjMatrix[y-1][x-1]=t;
	}
	int src,dest;
	cin>>src>>dest;
	solve(time , adjMatrix , n ,src-1 , dest-1);
}