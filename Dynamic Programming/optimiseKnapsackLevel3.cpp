#include<iostream>
using namespace std;
int knapsack(int *weight , int *value , int n , int maxWeight)
{
  //instead of n*maxWeight matrix we can make
  int **dp=new int*[2];
  dp[0]=new int[maxWeight+1];
  dp[1]=new int[maxWeight+1];
  //base case
  for(int i=0 ; i<=maxWeight ;i++)  dp[0][i]=0;
  dp[1][0]=0;
  int flag=1;
  for(int i=1;i<=n ; i++)
  {
    for(int j=1; j<=maxWeight ; j++)
    {
      dp[flag][j]=dp[flag^1][j];
      if(j>=weight[i-1])
      {
        dp[flag][j]=max(dp[flag][j] , value[i-1]+dp[flag^1][j-weight[i-1]]);
      }
    }
    flag^=1;
  }
  int ans=dp[flag^1][maxWeight];
  delete []dp[0];
  delete []dp[1];
  return ans;
}
int main(){
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
