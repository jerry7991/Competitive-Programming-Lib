#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
	int src,dest,weight;
};
inline int findParent(int src , int *parent){
	if(src==parent[src]) return src;
	return findParent(parent[src] , parent);
}
bool compare(Edge e1 , Edge e2){
	return e1.weight<e2.weight;
}
void printMst(Edge * wtMatrix , int v ,int e){
	//first sort the wtMatrix
	sort(wtMatrix , wtMatrix+e , compare);
	int *parent=new int[v];
	for(int i=0 ; i<v ;i++) parent[i]=i;
	int nMst=0 , nE=0;
	Edge *mst=new Edge[v-1];
	while(nMst!=(v-1) ){
		int src=wtMatrix[nE].src;
		int dest=wtMatrix[nE].dest;
        int srcParent=findParent(src , parent );
        int destParent=findParent(dest , parent );
		if(srcParent!=destParent) {
		mst[nMst].src=src;
		mst[nMst].dest=dest;
		mst[nMst].weight=wtMatrix[nE].weight;
		//make both parent same
		parent[destParent]=srcParent;
		nMst++;
        }
		nE++;
	}
	//no need of parent
	delete []parent;
	int totalWt=0;
	for(int i=0 ; i<nMst;i++)
	{
		totalWt+=mst[i].weight;
	//cout<<min(mst[i].src  , mst[i].dest)<<" "<<max(mst[i].src , mst[i].dest)<<" "<<mst[i].weight<<'\n';
	}
	delete []mst;
}
int main(){
	int v,e;
	cin>>v>>e;
	Edge *wtMatrix=new Edge[e];
	for(int i=0 ; i<e  ; i++){
		cin>>wtMatrix[i].src;
		cin>>wtMatrix[i].dest;
		cin>>wtMatrix[i].weight;
	}
	printMst(wtMatrix , v,e);
	delete []wtMatrix;
	return 0;
}