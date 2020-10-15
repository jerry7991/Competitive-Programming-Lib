#include <iostream>
using namespace std;
char checkRow(char **grid , int n)
{
  for(int i=0 ; i<n ; i++)
  {
    bool ans=true;
    char ch=grid[i][0];
    for(int j=1 ; j<n;j++)
    {
      if(ch!=grid[i][j]) {ans=false;break;}
    }
    if(ans)
      return ch;
  }
  return '\0';
}
char checkCol(char **grid , int n)
{
  for(int i=0 ; i<n ; i++)
  {
    bool ans=true;
    char ch=grid[0][i];
    for(int j=1 ; j<n;j++)
    {
      if(ch!=grid[j][i]) {ans=false;break;}
    }
    if(ans)
      return ch;
  }
  return '\0';
}
char checkDia(char **grid , int n)
{
  char ch=grid[0][0];
  int i=1 , j =1 ;
  while(i<n && j<n)
  {
    if(grid[i][j]!=ch)break;
    i++;j++;
  }
  if(i==n && j==n)  return ch;

  ch=grid[0][n-1];
  i=1,j=n-2;
  while(i<n && j>=0)
  {
    if(grid[i][j]!=ch)break;
    i++;j--;
  }
  if(i==n && j==0)  return ch;
  return '\0';
}
char checkWinner(char **grid , int n)
{
  char inRow=checkRow(grid,3);
  if(inRow!='\0')
    return inRow;
  char inCol=checkCol(grid , 3);
  if(inCol!='\0')
    return inCol;
  char diagonal=checkDia(grid , 3);
  if(diagonal!='\0')
    return diagonal;
  return '\0';
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
