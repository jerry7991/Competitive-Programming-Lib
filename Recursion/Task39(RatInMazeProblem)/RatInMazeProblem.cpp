#include<bits/stdc++.h>
using namespace std;
void printSolution(int **solution , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(solution[i][j]!=1)
            {
                cout<<0<<" ";
            }else{
                cout<<solution[i][j]<<" ";
            }
        }
    }
    cout<<endl<<endl;
}
void mazeHelp(int maze[][20] ,  int n, int ** solution , int row , int col)
{
    if(row==n-1 && col==n-1)//that's means we rat found their end points
    {
        //make (row,col) as visited
        solution[row][col]=1;
        printSolution(solution , n);
        return;
    }
    if(row>= n || col>=n || row<0 || col<0 || maze[row][col] ==0 || solution[row][col]==1)
    {
        //solution[row][col]==1 means rat started moving in circular
        //maze[row][col] ==0 means maze has block hole rat can't move further
        //row>= n || col>=n || row<0 || col<0 means rat reached out of maze so return simply and make rat into maze
        return;
    }
    //otherwise make (row,col) as visited and start exploring the way from left,right,top,down of (row,col)
    solution[row][col]=1;
    mazeHelp(maze , n , solution , row-1 , col);//for upper move
    mazeHelp(maze , n , solution , row+1 , col);//for lower move
    mazeHelp(maze , n , solution , row , col-1);//for left move
    mazeHelp(maze , n , solution , row, col+1);//for right move
    //and backtrack to current (row,col) and make it as unvisited so that it will use further for new way
    solution[row][col]=0;
}
void ratInAMaze(int maze[][20], int n)
{
    int ** solution=new int*[n];
    for(int i=0 ; i<n;i++)
    {
        solution[i]=new int[n];
    }
    mazeHelp(maze, n, solution, 0 , 0);
}
int main()
{
  int n;
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++)
    {
	for(int j = 0; j < n; j++)
	{
        	cin >> maze[i][j];
        }
  }
  ratInAMaze(maze, n);
}



