#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define mod 1000000007
#define pb push_back
#define fon(i,n) for( int i=0 ; i<n ; i++)
#define ui	unsigned int
#define ll long long
#define ull unsigned long long 
#define uos unordered_set
#define upm unordered_map
using namespace std;
class Edge{
public:
	int src,dest,weight;
};
bool compare(Edge e1 , Edge e2){
	return e1.weight<e2.weight;
}
bool isPath(vector<int> *adjList , int src , int dest,int nV){
	if(src==dest) return true;
	bool *visited=new bool[nV];
	fon(i,nV) visited[i]=false;
	visited[src]=true;
	queue<int> q;
	q.push(src);
	while(q.size()){
		int adjacent=q.front();q.pop();
		fon(i,adjList[adjacent].size()){
			int node=adjList[adjacent][i];
			if(node==dest){
			delete []visited;
			 return true;
			}
			if(visited[node]) continue;
			visited[node]=true;
			q.push(node);
		}
	}
	delete []visited;
	return false;
}
void getMst( Edge *wtList , Edge *mst,int &nV , int &nE){
	vector<int> *adjList=new vector<int> [nV];
	int nMst=0,i=0;
	while(nMst<(nV-1) &&i<nE){
		int src=wtList[i].src;
		int dest=wtList[i].dest;
		if(isPath(adjList , src , dest,nV)){
			i++;continue;
		}
		//store the path in adjList i.e. mst has path from src->Dest
		adjList[src].pb(dest);
		adjList[dest].pb(src);//because mst is undirected i.e. mst is a tree we can reach from any node to any node
		mst[nMst].src=src;
		mst[nMst].dest=dest;
		mst[nMst].weight=wtList[i].weight;
		nMst++;
		i++;
	}
	delete []adjList;
}
int main(){
	int nV,nE;
	cin>>nV>>nE;
	Edge * weightList=new Edge[nE];
	fon(i,nE){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		weightList[i].src=src;
		weightList[i].dest=dest;
		weightList[i].weight=weight;
	}
	sort(weightList , weightList+nE , compare);
	//fon(i,nE)	cout<<weightList[i].src<<"->"<<weightList[i].dest<<" ["<<weightList[i].weight<<"]";
	Edge * mst=new Edge[nV];
	getMst(weightList , mst , nV , nE);
	fon(i,nV-1){
		if(mst[i].src<mst[i].dest)
			cout<<mst[i].src<<" "<<mst[i].dest<<" "<<mst[i].weight<<'\n';
		else
			cout<<mst[i].dest<<" "<<mst[i].src<<" "<<mst[i].weight<<'\n';
	}
	//remove heap memory
	delete []weightList;
	delete []mst;
}