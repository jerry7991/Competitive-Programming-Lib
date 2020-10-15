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
void dfs(vector<int>*adjList ,set<int>*component , bool *visited , int curr){
	visited[curr]=true;
	component->insert(curr);
	fon(i,adjList[curr].size()){
		int adjacent=adjList[curr][i];
		if(visited[adjacent]) continue;
		dfs(adjList  , component, visited , adjacent);
	}
}
void printACC(vector<int>* adjList , int &v){
	bool *visited=new bool[v];
	set<set<int>*>* acc=new set<set<int>*>();
	fon(i,v){
		if(visited[i]) continue;
		set<int> * component=new set<int>();
		dfs(adjList , component , visited , i);
		acc->insert(component);
	}
	set<set<int>*> ::iterator itr=acc->begin();
	while(itr!= acc->end()){
		set<int> *component=*itr;
		for(set<int> :: iterator i=component->begin() ; i!=component->end() ; i++) cout<<*i<<' ';
		cout<<'\n';
		itr++;
	delete component;
	}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int v,e;
	cin>>v>>e;
	vector<int>* adjList=new vector<int>[v];
	fon(i,e){
		int s,d;
		cin>>s>>d;
		adjList[s].pb(d);
		adjList[d].pb(s);
	}
	printACC(adjList , v);
    return 0;
}