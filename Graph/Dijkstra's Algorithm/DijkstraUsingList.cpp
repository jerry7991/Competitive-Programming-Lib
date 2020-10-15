#include<iostream>
#include <vector>
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
int getMinVet(bool *inMST , int *distance ,int &v){
	int minVert=-1;
	fon(i,v){
		if(!inMST[i] && ((minVert<0) || (distance[minVert]>distance[i]))) minVert=i;
	}
	return minVert;
}
void dijkstra(vector<pair<int,int>> *adjList,int &v){
	 bool *inMST=new bool[v];
	 int *distance=new int[v];
	 fon(i,v){
	 	inMST[i]=false;
	 	distance[i]=infinte;
	 }
	 //make source as 0
	 distance[0]=0;
	 inMST[0]=0;
	 fon(i,v-1){
	 	int currSrc=getMinVet(inMST , distance , v);
	 	inMST[currSrc]=true;
	 	for(auto x: adjList[currSrc]){
	 		int dest=x.first;
	 		int weight=x.second;//distance from currSrc to dest
	 		if(!inMST[dest] && distance[dest]>(weight+distance[currSrc])){
	 			distance[dest]=weight+distance[currSrc];
	 		}
	 	}
	 }
	 fon(i,v){
	 	cout<<i<<" "<<distance[i]<<endl;
	 }
	 delete []inMST;
	 delete []distance;      
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<pair<int,int>> *adjList=new vector<pair<int,int>>[v];
	fon(i,e){
		int x,y,wt;
		cin>>x>>y>>wt;
		adjList[x].pb(mp(y,wt));
		adjList[y].pb(mp(x,wt));
	}
	dijkstra(adjList , v);
	return 0;
}