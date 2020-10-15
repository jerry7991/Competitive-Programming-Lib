#include <iostream>
using namespace std;
int getMaxSumRect(int **grid , int row , int col , int i , int j)
{
  if(i==(row-1) && j==(col-1))
  {
    return grid[i][j];
  }
  if(i>=row || j>=col)
  {
    return INT_MIN;
  }
}
int main()
{
  int row,col;
  cin>>row>>col;
  int **grid=new int*[row];
  for(int i=0;i<row ; i++)
  {
    grid[i]=new int[col];
    for(int j=0 ; j<col ; j++)
    {
      int x;
      cin>>x;
      grid[i][j]=x;
    }
  }
  cout<<getMaxSumRect(grid ,row ,col , 0 , 0)<<endl;
  for(int i=0 ; i<row;i++)
    delete [] grid[i];
  delete []grid;
  return 0;
}
