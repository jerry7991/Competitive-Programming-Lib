#include<iostream>
#include <vector>
#define mod 1000000007
#define pb push_back
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
#define infinte 2147483647
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
int getMinVert(bool *visited , int *weight , int &v){
	int minVert=-1;
	fon(i,v){
		if(!visited[i] && ((minVert<0) || (weight[minVert]>weight[i]))) minVert=i;
	}
	return minVert;
}
void prims(vector<pair<int,int>> * adjList , int &v){
	int *parent=new int[v];
	bool *visited=new bool[v];
	int *weight=new int[v];
	fon(i,v) weight[i]=infinte , visited[i]=false;
	weight[0]=0;//i.e. source weight
	parent[0]=-1;
	fon(i ,v-1){ //cause n-1 edgse need for mst
		int minVert=getMinVert(visited , weight , v);
		visited[minVert]=true;
		//explore all the neighbour
		for(auto x:adjList[minVert]){
			int u=x.first;
			int wt=x.second;
			if(!visited[u] && weight[u]>wt){
				weight[u]=wt;
				parent[u]=minVert;
			}
		}
	}
	//print mst
	for(int i=1 ; i<v;i++){
		cout<<(min(i,parent[i]))<<' '<<(max(i,parent[i]))<<' '<<weight[i]<<'\n';
	}
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>> *adjList=new vector<pair<int,int>>[v];
	fon(i,e){
		int src,dest,wt;
		cin>>src>>dest>>wt;
		adjList[src].pb(mp(dest ,wt));
		adjList[dest].pb(mp(src ,wt));
	}
	prims(adjList ,v);
	return 0;
}