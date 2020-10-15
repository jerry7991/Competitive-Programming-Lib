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
int v,e;
bool *visited;
vector<int> *adjList;
vector<int> *transList;
void dfs(int curr , stack<int>& fTime){
	visited[curr]=true;
	fon(i , adjList[curr].size()){
		int adjacent=adjList[curr][i];
		if(!visited[adjacent])
			dfs(adjacent , fTime);
	}
	fTime.push(curr);
}
void dfs(int curr , uos<int>* comp){
	visited[curr]=true;
	comp->insert(curr);
	fon(i,transList[curr].size()){
		int adjacent=transList[curr][i];
		if(!visited[adjacent])
				dfs(adjacent , comp);
	}
}
void solve(){
	adjList=new vector<int>[v];
	transList=new vector<int>[v];
	visited=new bool[v];
	stack<int> fTime;
	fon(i,v) visited[i]=false;
	fon(i,e){
		int x,y;cin>>x>>y;
		adjList[x-1].pb(y-1);
		transList[y-1].pb(x-1);
	}
	fon(i,v){
		if(!visited[i])
			dfs(i , fTime);
	}
	fon(i,v) visited[i]=false;
	uos<uos<int>*>* SCC=new uos<uos<int>*>();
	while(fTime.size()){
		int curr=fTime.top();
		fTime.pop();
		if(visited[curr]) continue;
		uos<int>*comp=new uos<int>();
		dfs(curr , comp);
		SCC->insert(comp);
	}
	uos<uos<int>*>:: iterator i;
	uos<int>:: iterator j;
	set<set<int>*>* bottom=new set<set<int>*>();
	for(i=SCC->begin(); i!=SCC->end(); i++){
		uos<int>* comp=*i;
		set<int>*currBot=new set<int>();
		bool flag=true;
		for(j=comp->begin(); j!=comp->end();j++){
			fon(k , adjList[*j].size()){
				int curr=adjList[*j][k];
				if(comp->find(curr)==comp->end())
				{
					flag=false;
					 break;
				}
			}
			currBot->insert(*j);
			if(!flag) break;
		}
		if(flag) bottom->insert(currBot);
		delete comp;
	}
	set<set<int>*>::iterator st;
	set<int>::iterator bt;
	set<int> output;
	for(st=bottom->begin(); st!=bottom->end() ; st++){
		set<int>* st2=*st;
		for(bt=st2->begin(); bt!=st2->end() ; bt++) output.insert(*bt+1);
		delete st2;
	}
	for(bt=output.begin(); bt!=output.end() ; bt++) printf("%d", *bt);
	printf("\n");
	//release memory
	delete []adjList;
	delete []transList;
	delete []visited;
	delete SCC;
	delete bottom;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 while(true)
 {  
 	cin>>v;
 	if(v)	cin>>e;
 	else return 0;
	solve();
 }
    return 0;
}