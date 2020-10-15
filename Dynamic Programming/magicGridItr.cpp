#include <iostream>
using namespace std;
int getMinHealth(int **grid , int row , int col)
{
  //we need a dp array
  int **dp=new int*[row];
  for(int i=0 ; i<row ; i++)
  {
    dp[i]=new int[col];
  }
  //now ower base case is:-
  dp[row-1][col-1]=1;//i.e. min health required at the last position
  //let's feel other base case
  //base case for row
  for(int i=row-2 ; i>=0 ; i--)
  {
    dp[i][col-1]=dp[i+1][col-1]-grid[i][col-1];
    if(dp[i][col-1]<0)
      dp[i][col-1]=1;
  }
  for(int j=col-2 ; j>=0 ; j--)
  {
    dp[row-1][j]=dp[row-1][j+1]-grid[row-1][j];
  }
  for(int i=row-2;i>=0 ; i--)
  {
    for(int j=col-2 ; j>=0 ; j--)
    {
      int rightMove=dp[i][j+1]-grid[i][j];
      int bottumMove=dp[i+1][j]-grid[i][j];
      dp[i][j]=min(rightMove , bottumMove);
      if(dp[i][j]<0)
        dp[i][j]=1;
    }
  }
  int ans=dp[0][0];
  for(int i=0 ; i<row ; i++)
    delete [] dp[i];
  delete []dp;
  return ans;
}
int main()
{
  int test;
  cin>>test;
  while (test--) {
    int row,col;
    cin>>row>>col;
    int **grid=new int*[row];
    for(int i=0 ;i<row ; i++)
    {
      grid[i]=new int[col];
      for(int j=0 ; j<col ; j++)
      {
        int x;
        cin>>x;
        grid[i][j]=x;
      }
    }
    cout<<getMinHealth(grid , row , col)<<endl;
    for(int i=0 ;i<row ; i++)
      delete []grid[i];
    delete []grid;
  }
}
