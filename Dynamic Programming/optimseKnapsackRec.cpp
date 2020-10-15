#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int solve(int *weights , int *values , int n , int maxWeight , int **dp)
{
  //base case
  if(maxWeight<=0 || n==0)  return 0;
  //if we have allready one solution
  if(dp[n][maxWeight]!=-1) return dp[n][maxWeight];
  int opt1=0,opt2=0;
  if(maxWeight>=weights[n-1])
  {
    opt1=values[n-1]+solve(weights , values , n-1 , maxWeight-weights[n-1],dp) ;
  }
    opt2=solve(weights , values ,  n-1 , maxWeight , dp);
    return dp[n][maxWeight]=max(opt1 , opt2);
}
int knapsack(int *weight , int *values  , int n , int maxWeight)
{
  int **dp=new int*[n+1];
  fon(i,n+1)
    {
      dp[i]=new int[maxWeight+1];
      fon(j , maxWeight+1)  dp[i][j]=-1;
    }
    int ans=solve(weight , values , n , maxWeight , dp);
    fon(i,n+1)  delete []dp[i];
    delete[] dp;
    return ans;
}
int main()
{
  int n;
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];
  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }
  for(int i = 0; i < n; i++){
    cin >> values[i];
  }
  int maxWeight;
  cin >> maxWeight;
  cout << knapsack(weights, values, n, maxWeight);
}
