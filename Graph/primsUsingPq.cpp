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
void prims(vector<pair<int,int>>*adjList , int &v){
	//min priority queue
	priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
	int src=0;//taking source vertex as 0
	//create vector for key and intilize as infinte
	int *weight=new int[v];
	//to store parent arr
	int *parent=new int[v];
	//to keep track of vertices which allready has been included in mst
	bool *inMST=new bool[v];
	fon(i,v){
		weight[i]=infinte;
		parent[i]=-1;
		inMST[i]=false;
	}
	//insert source as in priority queue and initialize with 0
	inMST[src]=true;
	pq.push(mp(0 , src));//0 weight for current source
	weight[src]=0;//weight from source to source
	while(!pq.empty()){
		//the first vertex int pair is the minimum weight vertex ,extract it from
		//priority queue . and node name is stored at the second of pair( it has to be
		// be done this way to keep the vertices sorted order with respect weight)
		//weight must be first item in pair
		int u=pq.top().second;
		pq.pop();
		//include u to in our mst
		inMST[u]=true;
		//explore all adjacent of u and if not visited the relax them
		for(auto x: adjList[u]){
			int v=x.first;
			int wt=x.second;
			//if v is not in mst and weight of (u,v) is smaller then the current weight
			//of v
			if(!inMST[v] && weight[v]>wt){
				//update weight of v
				weight[v]=wt;
				pq.push(mp(weight[v] , v));//insert it into the priority queue
				parent[v]=u;
			}
		}
	}
	for(int i=1; i<v;i++){
		cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
	}
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>> *adjList=new vector<pair<int,int>>[v];
	fon(i,e){
		int x,y,wt;
		cin>>x>>y>>wt;
		adjList[x].pb(mp(y,wt));
		adjList[y].pb(mp(x,wt));
	}
	prims(adjList , v);
	delete []adjList;
	return 0;
}