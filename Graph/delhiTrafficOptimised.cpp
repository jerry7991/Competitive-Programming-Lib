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
int kruskal(int &v ,vector<pair<int,int>>* adjList,int *time , int &src ,int &dest){
	ll *timeTill=new ll[v];
    bool *inMst=new bool[v];
	fon(i,v) timeTill[i]=infinte,inMst[i]=false;
	priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
	pq.push(mp(0,src));
    timeTill[src]=0;
	while(pq.size()){
		int u=pq.top().second;
		int currTime=pq.top().first;
        inMst[u]=true;
		pq.pop();
		if(u==dest) break;
		for(auto x: adjList[u]){
			int V=x.first;
            if(x.second==0 || inMst[V]) continue;
			ll wtTime=x.second+timeTill[u];
			if( wtTime%time[V]!=0 && V!=dest){
				wtTime+=(time[V]-wtTime%time[V]);
			}
			if(wtTime<timeTill[V]){
				timeTill[V]=wtTime;
				pq.push(mp(wtTime , V));
			}
		}
	}
	int ans=timeTill[dest];
	delete []timeTill;
	return ans;
}
void solve(){
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>> * adjList=new vector<pair<int,int>>[v];
	int *time=new int[v];
	fon(i,v) cin>>*(time+i);
	//fon(i,v) cout<<time[i]<<'\n';
	fon(i,e){
		int x,y,t;
		cin>>x>>y>>t;
		adjList[x-1].pb(mp(y-1,t));
		adjList[y-1].pb(mp(x-1,t));
	}
	int src,dest;
	cin>>src>>dest;src--;dest--;
	int answer=kruskal(v,adjList , time,src ,dest);
	cout<<answer<<endl;
	delete []adjList;
	delete []time;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	solve();
    return 0;
}
//time complexiyt eLogV