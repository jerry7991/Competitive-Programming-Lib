#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define infinte 2147483647
#define ui	unsigned int
#define fon(i,n) for(ui i=0 ; i<n ; i++)
#define ll long long int
#define ull unsigned long long int
#define uos unordered_set
#define ump unordered_map
#define mp make_pair
using namespace std;
inline int max(int a,int b){ return (a>b)?a:b;}
inline int min(int a,int b){ return (a>b)?b:a;}
void dfs(vector<int>*adjList , bool *visited , set<int>*comp , int cur){
	visited[cur]=true;
	comp->insert(cur);
	fon(i , adjList[cur].size()){
		int adjacent=adjList[cur][i];
		if(visited[adjacent]) continue;
		dfs(adjList , visited , comp , adjacent);
	}
}
void solve(){
	ui n,m;
	cin>>n>>m;
	int *p=new int[n];
	int *q=new int[n];
	bool *visited =new bool[n];
	fon(i,n) cin>>*(p+i) , visited[i]=false;
	fon(i,n) cin>>*(q+i);
	vector<int> *adjList=new vector<int>[n];
	while(m--){
		int ai,bi;cin>>ai>>bi;
		adjList[ai-1].pb(bi-1);
		adjList[bi-1].pb(ai-1);
	}
	set<set<int>*>* acc=new set<set<int>*>();
	fon(i,n){
		if(visited[i]) continue;
		set<int> *comp=new set<int>();
		dfs(adjList , visited  , comp , i);
		acc->insert(comp);
	}
	set<set<int>*>::iterator i;
	set<int> ::iterator j,k;
	for(i=acc->begin();i!=acc->end() ;i++){
		set<int> *comp=*i;
		for(j=comp->begin();j!=comp->end() ; j++){
			int x=p[*j];
			for(k=comp->begin() ; k!=comp->end()  ;k++){
				if(x==q[*k]) break;
			}
			if(k==comp->end()){	//i.e. correspond to q is not found in same components
				cout<<"No"<<'\n';
				return;	
			}
		}
	delete comp;
	}
	cout<<"Yes"<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
    return 0;
}