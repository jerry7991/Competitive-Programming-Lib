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
int date;
class Data{
public:
	int ai;//number of people
	int bi;//number of fruits
	int date;
	Data(){
		ai=0;
		bi=0;
		date=0;
	}
};
void dfs(bool **edge , Data *data , bool *visited  ,int src , Data currData , int n){
	data[src].bi-=min(data[src].bi , currData.ai);
	if(data[src].bi<=0){
		data[src].date=date;
	}
	fon(i,n){
		if(edge[src][i] && !visited[i] && data[i].bi>0){
			dfs(edge , data , visited , i , currData, n);
		}
	}
}
void solve(){
	date=0;
	int n;cin>>n;
	bool **edge=new bool*[n];
	bool *visited=new bool[n];
	Data *data=new Data[n];
	fon(i,n){
		data[i].ai=data[i].bi=data[i].date=-1;
		edge[i]=new bool[n];
		visited[i]=false;
		fon(j,n) edge[i][j]=false;
	}
	fon(i,n-1){
		int u,v;cin>>u>>v;
		edge[u-1][v-1]=true;
		edge[v-1][u-1]=true;
	}
	vector<int>v;
	fon(i,n){
		int x;
		cin>>x;
		v.pb(x-1);
	}
	fon(i,v.size())	cin>>data[v[i]].ai;
	fon(i,v.size())	cin>>data[v[i]].bi;
	fon(i , v.size()){
		if(visited[v[i]]) continue;
		date++;
		visited[i]=true;
		dfs(edge , data ,visited , v[i] , data[v[i]] , n);
	}
	//fon(i ,n) cout<<" "<<data[i].ai<<" "<<data[i].bi<<" "<<data[i].date<<'\n';
	fon(i,n)
	cout<<data[i].date<<' ';
	cout<<'\n';
	fon(i,n) delete []edge[i];
	delete [] visited;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) solve();
    return 0;
}