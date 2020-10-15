#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int output[20][20];
void print(int n){
	fon(i ,n)
		fon(j , n) cout<<output[i][j]<<" ";
	cout<<endl;
}
void printPath(int maze[][20] , int row, int col,int n){
	if(row==n-1 && col==n-1){
		print(n);
		return;
	}
	//rat moves
	//right moves
	if(col+1<n && !output[row][col+1] && maze[row][col+1]){
		output[row][col+1]=1;
		printPath(maze , row , col+1,n);
		//backtrack
		output[row][col+1]=0;
	}
	//left move
	if(col>0 && !output[row][col-1] && maze[row][col-1]){
		output[row][col-1]=1;
		printPath(maze , row ,col-1 , n);
		//backtrack
		output[row][col-1]=0;
	}
	//up move
	if(row>0 && !output[row-1][col] && maze[row-1][col]){
		output[row-1][col]=1;
		printPath(maze , row-1 , col , n);
		output[row-1][col]=0;
	}
	//down move
	if(row+1<n && !output[row+1][col] && maze[row+1][col]){
		output[row+1][col]=1;
		printPath(maze , row+1, col , n);
		output[row+1][col]=0;
	}
}
void ratInAMaze(int maze[][20] , int n){
	output[0][0]=1;
		printPath(maze , 0 , 0,n);
}
int main(){
	int maze[20][20];
	int n;
	cin>>n;
	fon(i,n){
		fon(j,n)
		{
			cin>>maze[i][j];
			output[i][j]=0;
		}
	}
	ratInAMaze(maze , n);
}