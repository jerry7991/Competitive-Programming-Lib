#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define infinte 2147483647
#define fon(i,n) for(unsigned int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
	vector<pair<int,double>> *adjList=new vector<pair<int,double>>[n];
	//make an adjaceny list 
	fon(i,edges.size()){
		 	adjList[edges[i][0]].pb(mp(edges[i][1],succProb[i]));
		 	adjList[edges[i][1]].pb(mp(edges[i][0],succProb[i]));
	}
	bool *visited=new bool[n];//represent weather our current vertex is included in mst or not
	double *prob=new double[n];//give the max probibilty from start to end
	fon(i,n)visited[i]=false ,prob[i]=0.0000;
	prob[start]=1;//current node is always a reachable with current node
	priority_queue<pair<double ,int>> pq;
	pq.push(mp(1 ,start));//insert pq with 1 probability and start node
	while(pq.size()){
		int u=pq.top().second;
		visited[u]=true;
		double probU=pq.top().first;
		pq.pop();
		fon(i,adjList[u].size()){
			int v=adjList[u][i].first;
			if(visited[v]) continue;
			double probV=adjList[u][i].second;
			//if probability of start to v is lesser than the probability start to u and u to v..
			//this step called as relaxation
			if(prob[v]<(probU*probV)){
				prob[v]=probU*probV;
				pq.push(mp(prob[v] ,v));
			}
		}
	}
	double ans=prob[end];
	delete []prob;
	delete []visited;
	delete []adjList;
	return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int n;
	cin>>n;
	int e;
	cin>>e;
	vector<vector<int>>edge;
	fon(i,e){
		vector<int> v;
		int x,y;
		cin>>x>>y;
		v.pb(x);v.pb(y);
		edge.pb(v);
	}
	vector<double> succProb;
	fon(i,e){
		double x;cin>>x;
		succProb.pb(x);
	}
	int src ,dest;
	cin>>src>>dest;
	cout<<maxProbability(n ,edge , succProb ,src , dest);
    return 0;
}