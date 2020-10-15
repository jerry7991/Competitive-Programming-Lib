#include <iostream>
using namespace std;
int **dp;
int getMinHealth(int **grid , int row ,int col, int i , int j)
{
  //base case
    //if we are last node then we need only one health
  if(row==i && col==j)
  {
    return 1;
  }
  //boundry condition
  if(i>row || j>col)
  {
    return 1000;//we can't win have to return max value for which it wouldn't include
  }
  if(dp[i][j]>-1) return dp[i][j];
  //now fighter can move in two direction either in right or in bottum
  int rightMove=getMinHealth(grid , row , col ,i , j+1)-grid[i][j];
  int bottumMove=getMinHealth(grid , row,col,i+1,j)-grid[i][j];//subtract the health at which grid we are going to jump
  int health=min(rightMove , bottumMove);
  if(health<=0)
    health=1; //cause we have to maintain min health >0 other wise fighter lossed
  return dp[i][j]=health;
}
int main()
{
  int test;
  cin>>test;
  while (test--) {
    int row,col;
    cin>>row>>col;
    int **grid=new int*[row];
    dp=new int*[row];
    for(int i=0 ;i<row ; i++)
    {
      grid[i]=new int[col];
      dp[i]=new int[col];
      for(int j=0 ; j<col ; j++)
      {
        int x;
        cin>>x;
        grid[i][j]=x;
        dp[i][j]=-1;
      }
    }
    cout<<getMinHealth(grid , row-1 , col-1,0 ,0)<<endl;
  }
}
