#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int getMinVertex(bool *visited , int *distance , int n){
	int minVert=-1;
	fon(i,n){
		if(!visited[i] && ((minVert<0) || (distance[minVert]>distance[i]))) minVert=i;
	}
	return minVert;
}
void Dijkstra(int **matrix , int v){
	bool *visited=new bool[v];
	int *distance=new int[v];
	fon(i,v) 
	{
		visited[i]=false;
		distance[i]=INT_MAX;
	}
	distance[0]=0;
	fon(i,v-1){
		int currSrc=getMinVertex(visited , distance,v);
		visited[currSrc]=true;
		fon(j,v){
			if(matrix[currSrc][j]!=0 && !visited[j]){
				if(distance[j]>(distance[currSrc]+matrix[currSrc][j]))//Relaxation
				 {
				 	distance[j]=distance[currSrc]+matrix[currSrc][j];
				 }
			}
		}
	}
	for(int i=0; i<v;i++) cout<<i<<" "<<distance[i]<<endl;
	delete []visited;
	delete []distance;
}
int main(){
	int v,e;
	cin>>v>>e;
	int **matrix=new int*[v];
	fon(i , v){
		matrix[i]=new int[v];
		fon(j,v) matrix[i][j]=0;
	}
	fon(i,e){
		int x,y,wt;
		cin>>x>>y>>wt;
		matrix[x][y]=wt;
		matrix[y][x]=wt;
	}
	Dijkstra(matrix , v);
}