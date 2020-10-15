#include<iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int knapsack(int *weights ,int *values , int n , int maxWeight)
{
  //want to do it recursively
  int **dp=new int*[n+1];
  fon(i,n+1){
    dp[i]=new int[maxWeight+1];
  }
  //base case
  //if weight=0 ; profit 0 and if value 0 profit also 0
  fon(i,n+1)  dp[i][0]=0;
  fon(i,maxWeight+1)  dp[0][i]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=maxWeight ; j++)
    {
      //one thing is common either we have required knapsack capacity or not
      dp[i][j]=dp[i-1][j];
      //if knapsack has required capacity
      if(j>=weights[i-1])
        dp[i][j]=max(dp[i][j] , values[i-1]+dp[i-1][j-weights[i-1]]);
    }
  }
  fon(i,n+1)
  {
    fon(j,maxWeight+1)cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  int ans=dp[n][maxWeight];
  fon(i,n+1)delete []dp[i];
  delete []dp;
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
