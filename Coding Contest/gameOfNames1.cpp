#include <iostream>
using namespace std;
bool isWinner(char **grid ,int i , int j ,int n , int k=3)
{
  if(i>=n || j>=n)  return false;
  if(k==0)  return true;
  bool ans=false;
  if(i+1<n && grid[i][j]==grid[i+1][j])
    ans |=isWinner(grid , i+1 , j ,n,k-1);
  if(i+1 <n && j+1<n && grid[i][j]==grid[i+1][j+1])
    ans |=isWinner(grid , i+1 , j+1,n , k-1);
  if(j+1<n && grid[i][j]==grid[i][j+1])
    ans |=isWinner(grid , i , j+1,n , k-1);
  return ans;
}
char checkWinner(char** grid , int n)
{
  for(int i=0 ; i<n ; i++)
  {
    for(int j=0 ; j<n ; j++)
    {
      bool ans=isWinner(grid , i , j,n);
      if(ans)
      {
        return grid[i][j];
      }
    }
  }
}
int main()
{
  int n;
  cin>>n;
  char **grid=new char*[n];
  for(int i=0;i<n;i++)
    {
      grid[i]=new char[n];
      for(int j=0 ; j<n;j++)
      {
        char ch;
        cin>>ch;
        grid[i][j]=ch;
      }
    }
  char ch=checkWinner(grid ,n);
  if(ch=='\0')
  {
    cout<<"Ongoing";
  }else if(ch=='.')
  {
    cout<<"Ongoing";
  }
  else{
    cout<<ch;
  }
}
