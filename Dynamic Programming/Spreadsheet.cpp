#include <bits/stdc++.h>
#include <iostream>
#define fon(i,k,n) for(int i=k ; i<n ; i++)
#define cin(x) int x;cin>>x;
using namespace std;
void getQueryOut(int **grid , int *output , int row ,int col)
{
  int **dp=new int*[row];
  fon(i,0,row)
  {
    dp[i]=new int[col];
  }
  //now base case
  fon(i ,0, col) dp[0][i]=1;
  fon(i,1,row)
  {
    fon(j,0,col)
    {
      dp[i][j]=(grid[i][j]>grid[i-1][j])?(1+dp[i-1][j]):1;//i.e. max length of increasing row
    }
  }
  fon(i,0,row)
  {
    int maxV=INT_MIN;
    fon(j,0,col)  maxV=(dp[i][j]>maxV)?dp[i][j]:maxV;
    output[i]=maxV;
    //remove memory too
    delete [] dp[i];
  }
}
int main()
{
  int row,col;
  cin>>row>>col;
  int **grid=new int*[row];
  fon(i,0,row)
  {
    grid[i]=new int[col];
    fon(j,0,col)
    {
      cin(x);
      grid[i][j]=x;
    }
  }
  int *queryOut=new int[row];
  getQueryOut(grid , queryOut , row , col);
  fon(i,row)  delete[] grid[i];
  delete[] grid;
  cin(nQuery);
  while (nQuery--) {
    cin(left);cin(right);
    if(queryOut[right-1]>(left-1))
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }
}
