#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define infinte 2147483647
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
int prims(vector<pair<int,int>> *adjList , int &v , int src , int dest ,int petrol){
	int * parent=new int[v];
	int *weight=new int[v];
	for(int i=0 ; i<v ; i++) weight[i]=infinte  , parent[i]=-1;
	priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
	//start from source
	weight[src]=0;
	pq.push(mp(0 , src));//first pair is weight which work as like comperator for pq
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		for(auto x: adjList[u]){
			int v=x.first;
			int wt=x.second;
			//if v is not in mst
			if( weight[v]>weight[u]+wt){
				weight[v]=weight[u]+wt;
				parent[v]=u;
				pq.push(mp(wt , v));
			}
		}
	}
// 	for(int i=0 ; i<v;i++) cout<<weight[i]<<" ";
	if(weight[dest]<=petrol) return 1;
	return 0;
}
void solve(){
	int v,e,petrol;
	cin>>v>>e>>petrol;
	vector<pair<int,int>> *adjList=new vector<pair<int,int>>[v];
	fon(i,e){
		int x,y,wt;
		cin>>x>>y>>wt;
        if(wt==0) continue;
		adjList[x-1].pb(mp(y-1 , wt));
		adjList[y-1].pb(mp(x-1 , wt));
	}
	int src,dest;
	cin>>src>>dest;
	if(prims(adjList , v , src-1 , dest-1,petrol))
        cout<<"Yes";
    else
        cout<<"No";
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	solve();
    return 0;
}
/*
6 10 2
1 2 8
1 3 2
1 4 3
2 4 5
2 3 4
3 5 7
3 6 1
4 5 6
4 6 5
5 6 9
1 6
*/