#include <iostream>
using namespace std;
int getMinVertex(bool *visited , int *weight , int n){
	int minVertex=-1;
	for(int i=0 ; i<n  ; i++){
		if(!visited[i] &&((minVertex<0) || weight[i]<weight[minVertex]))
				minVertex=i;
	}
	return minVertex;
}
void prims(int **wtMatrix , int n){
	bool *visited=new bool[n]();
	int *weight=new int[n];
	for(int i=0 ; i<n ; i++) weight[i]=INT_MAX;
	int *parent =new int[n];
	parent[0]=-1;
	weight[0]=0;
	for(int i=0 ; i<n-1 ; i++){
		int minVertex=getMinVertex(visited , weight , n);
		//make minVertex as visited
		visited[minVertex]=true;
		//explore all adjacent edges
		for(int j=0 ; j<n ;j++){
			if(wtMatrix[minVertex][j] && !visited[j]){
				if(wtMatrix[minVertex][j]<weight[j]){
					weight[j]=wtMatrix[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
	}
	//now print mst;
	for(int i=1;i<n ; i++){
		if(parent[i]>i){
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}else{
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}
	}
}
int main(){
	int v,e;
	cin>>v>>e;
	int **wtMatrix=new int*[v];
	for(int i=0;i<v ; i++){
		wtMatrix[i]=new int[v];
		for(int j=0 ; j<v;j++)wtMatrix[i][j]=0;
	}
	for(int i=0  ; i<e;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		wtMatrix[x][y]=wt;
		wtMatrix[y][x]=wt;
	}
	prims(wtMatrix , v);
	for(int i=0 ; i<v;i++) delete []wtMatrix[i];
	delete []wtMatrix;
return 0;
}