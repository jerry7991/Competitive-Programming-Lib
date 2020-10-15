#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int countPath(int **maze , int n , int m , int i=0  , int j=0){
	if(i==n-1 && j==m-1) return 1;//one way
	//boundry condition
	if(i>=n || j>=m) return 0;
	int left=0,bottum=0;
	if(i+1<n && maze[i+1][j]!=-1){
		left=countPath(maze , n , m , i+1 , j);
	}
	if(j+1<m && maze[i][j+1]!=-1){
		bottum=countPath(maze , n , m,i , j+1);
	}
	return (left+bottum);
}
int main(){
	int n,m;
	cin>>n>>m;
	int **maze;
	maze=new int*[n];
	fon(i,n)
	{
		maze[i]=new int[m];
		fon(j,m) cin>>maze[i][j];
	}
	cout<<countPath(maze , n  , m);
	fon(i,n) delete []maze[i];
	delete []maze;
	return 0;
}