#include <iostream>
#include <vector>
using namespace std;
int getMinVertex(bool *visited , int *weight ,int v){
	int minVertex=-1;
	for(int i=0 ; i<v;i++){
		if(!visited[i] && ((minVertex<0 )|| (weight[i]<weight[minVertex]))) minVertex=i;
	}
	return minVertex;
}
void prims(vector<pair<int,int>> *matrix , int v){
	bool *visited=new bool[v]();
	int *weight=new int[v];
	for(int i=0 ; i<v;i++) weight[i]=INT_MAX;
	int *parent=new int[v];
	parent[0]=-1;
	weight[0]=0;
	for(int i=0 ; i<v-1 ; i++){
		int minVertex=getMinVertex(visited , weight , v);
		visited[minVertex]=true;
		for(int i=0 ; i<matrix[minVertex].size() ; i++){
			int nb=matrix[minVertex][i].first;
			//nb instase for neighbour
			if(!visited[nb]){
				if(weight[nb]>matrix[minVertex][i].second){
					weight[nb]=matrix[minVertex][i].second;
					parent[nb]=minVertex;
				}
			}
		}
	}
	for(int i= 1 ; i<v; i++){
		cout<<min(parent[i],i)<<" "<<max(parent[i]  ,i )<<" "<<weight[i]<<endl;
	}
	delete []visited;
	delete []parent ;
	delete []weight;
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>> * matrix=new vector<pair<int,int>>[v] ;
	for(int i=0 ;i<e;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		matrix[x].push_back(make_pair(y,wt));
		matrix[y].push_back(make_pair(x,wt));
	}
	prims(matrix , v);
	delete []matrix;
	return 0;
}