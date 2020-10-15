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
int v;
vector<int>*adjList;
bool isSuspicious(bool *visited , int src){
	uos<int>*gender=new uos<int>[v];
	gender[0].insert(src);
	queue<int> pending;
	pending.push(src);
	while(pending.size()){
		int curr=pending.front();
		visited[curr]=true;
		pending.pop();
		int currGender= (gender[0].find(curr)==gender[0].end())?1:0;
		fon(i,adjList[curr].size()){
			int adjacent=adjList[curr][i];
			if( (gender[0].find(adjacent)==gender[0].end() )  && (gender[1].find(adjacent)==gender[1].end())){
				gender[currGender^1].insert(adjacent);
				pending.push(adjacent);
			}else if(gender[currGender].find(adjacent)!=gender[currGender].end()){
				delete []gender;
				return false;
			}
		}
	}
	delete []gender;
	return true;
}
bool solve(){
	int e;
	cin>>v>>e;
	adjList=new vector<int>[v];
	fon(i,e){
		int s,d;
		cin>>s>>d;
		adjList[s-1].pb(d-1);
		adjList[d-1].pb(s-1);
	}
	bool *visited=new bool[v];
	fon(i,v) visited[i]=false;
	bool ans=true;
	fon(i,v){
		if(visited[i]) continue;
			ans &=isSuspicious(visited ,i);
			if(!ans) break;
	}
	delete []visited;
	delete []adjList;
	return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		cout<<"Scenario #"<<i<<":"<<'\n';
		if(solve()){
			cout<<"No suspicious bugs found!"<<'\n';
		}else{
			cout<<"Suspicious bugs found!"<<'\n';
		}
	}
    return 0;
}