#include <iostream>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col)
{
  int **dp=new int*[row];
  for(int i=0 ; i<row ; i++)
  {
    dp[i]=new int[col];
  }
  //let's feel the our base case
  for(int i=0 ; i<row ; i++)
  {
    dp[i][0]=0;
    if(!arr[i][0]) dp[i][0]=1;
  }
  for(int i=0 ; i<col ; i++)
  {
    dp[0][i]=0;
    if(!arr[0][i])  dp[0][i]=1;
  }
  for(int i=1;i<row ; i++)
  {
    for(int j=1;j<col;j++)
    {
      if(arr[i][j]){
        dp[i][j]=0;
        continue;
      }
      dp[i][j]=min(dp[i-1][j] , min(dp[i-1][j-1] ,dp[i][j-1]))+1;
    }
  }
  int ans=0;
  for(int i=0 ; i<row;i++)
  {
    for(int j=0 ; j<col ; j++)
      ans=max(ans ,dp[i][j]);
    delete [] dp[i]  ;
  }
  return ans;
}
int main()
{
  int row,col;
  cin>>row>>col;
  int **grid=new int*[row];
  for(int i=0 ; i<row ; i++)
  {
    grid[i]=new int[col];
    for(int j=0 ; j<col ; j++)
      {
        int x;
        cin>>x;
        grid[i][j]=x;
      }
  }
  cout<<findMaxSquareWithAllZeros(grid , row ,col);
}
