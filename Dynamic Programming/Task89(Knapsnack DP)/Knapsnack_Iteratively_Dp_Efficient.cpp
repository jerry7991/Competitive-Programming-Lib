#include<iostream>
using namespace std;
int knapsack(int* weight, int* value, int n, int kWeight)
{
 int **dp=new int*[2];
  for (int i = 0; i <2; i++)
  {
    dp[i]=new int[kWeight+1];
  }

  //base case:-
  //base case 1:-
    //if kWeight is 0 then cann't put a single item in out knapsnack
    for (int i = 0; i <2; i++)
    {
      dp[i][0]=0;
    }
  //base case 2:-
    //if n is 0 then we have null item i.e. 0 to put into knapsnack
    for (int i = 0; i <=kWeight; i++)
    {
      dp[0][i]=0;
    }
  //now let's start fill the dp with the help of base case and recursive relation
    int flag=1;
    for (int i = 1; i <=n; i++)
    {
      for (int w = 0; w <=kWeight; w++)
      {
        //in best case or worst case we check about to not include of any item
        dp[flag][w]=dp[flag^1][w];//ignore i-th item and save knapsnack space
        if(weight[i-1]<=w)
        {
          //then check what happen when we put i-th element in knapsnack
          dp[flag][w]=max(  dp[flag][w] , value[i-1]+dp[flag^1][w-weight[i-1]]  );
        }
      }
            flag=flag^1;
    }
    int ans=dp[flag^1][kWeight];
  //release memory
  for (int i = 0; i <2; ++i)
  {
    delete [] dp[i];
  }
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
