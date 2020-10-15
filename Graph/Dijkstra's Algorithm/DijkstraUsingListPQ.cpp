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
void dijsktra(vector<pair<int,int>> *adjList , int &v){
	priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; 
	int *distance=new int[v];
	bool *inMST=new bool[v];
	fon(i,v) distance[i]=infinte , inMST[i]=false;
	int src=0;
	// insert source itself in priority queueu and initialize and its distance 0
	pq.push(mp(0,src));
	distance[src]=0;
	while(!pq.empty()){
		//the first vertex in pair is the min distance ,extract it from priority queue.
		//vertex label is sorted in second of pair (it has to be done this way to keep
		// the vertices sorted distance)
		int currSrc=pq.top().second;
		inMST[currSrc]=true;
		pq.pop();
		for(auto x: adjList[currSrc]){
			//get vertex and weight of current adjacent currSrc
			int dest=x.first;
			int weight=x.second;
			if(!inMST[dest] && distance[dest]>(distance[currSrc]+weight)){
				distance[dest]=distance[currSrc]+weight;
				//update priority queue to.
				pq.push(mp(distance[dest] , dest));
			}
		}
	}
	fon(i,v) cout<<i<<" "<<distance[i]<<endl;
	delete []distance;
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>>*adjList=new vector<pair<int,int>>[v];
	fon(i,e){
		int x,y,wt;
		cin>>x>>y>>wt;
		adjList[x].pb(mp(y,wt));
		adjList[y].pb(mp(x,wt));
	}
	dijsktra(adjList , v);
	return 0;
}