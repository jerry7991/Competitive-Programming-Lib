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
void dfs(vector<int>* adjList , bool *visited , stack<int> &vFinishTime , int curr){
	visited[curr]=true;
	fon(i , adjList[curr].size()){
		int adjacent=adjList[curr][i];
		if(!visited[adjacent])
			dfs(adjList , visited  , vFinishTime , adjacent);
	}
	//while backtrack
	vFinishTime.push(curr);
}
void dfs(vector<int> *adjList , bool *visited , set<int>* component , int curr){
	visited[curr]=true;
	component->insert(curr);
	fon(i , adjList[curr].size()){
		int adjacent=adjList[curr][i];
		if(!visited[adjacent]) 
				dfs(adjList , visited , component , adjacent);
	}
}
void solve(){
	int n,m;
	cin>>n>>m;
	if(n==0 || m==0) return;
	vector<int>* adjList=new vector<int>[n];
	vector<int>* tAdjList=new vector<int>[n];
	fon(i,m){
		int x,y;
		cin>>x>>y;
		adjList[x-1].pb(y-1);
		tAdjList[y-1].pb(x-1);
	}
	bool *visited=new bool[n];
	fon(i,n) visited[i]=false;
	stack<int> vFinishTime;
	fon(i,n){
		if(!visited[i])
				dfs(adjList , visited ,  vFinishTime , i);
	}
	fon(i,n) visited[i]=false;
	set<set<int>*>* SCC=new set<set<int>*>();
	while(vFinishTime.size()){
		int curr=vFinishTime.top();
		cout<<curr<<" ";
		vFinishTime.pop();
		if(visited[curr]) continue;
		set<int>*component=new set<int>();
		dfs(tAdjList , visited , component , curr);
		SCC->insert(component);
	}
	int count=0;
	set<set<int>*>::iterator i;
	set<int> :: iterator j;
	for(i=SCC->begin();i!=SCC->end() ; i++ , count++){
		set<int> *component=*i;
		for(j=component->begin();j!=component->end();j++) cout<<*j<<' ';
		cout<<'\n';
	delete component;
	}
	delete []visited;
	delete []adjList;
	delete []tAdjList;
	cout<<count<<endl;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
    return 0;
}