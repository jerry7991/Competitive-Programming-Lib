#include<iostream>
using namespace std;
int knapsack(int *weights , int *values , int n , int maxWeight)
{
  //base case
  if(n==0 || maxWeight==0)  return 0;
  int opt1=0,opt2=0;
  if(maxWeight>=weights[n-1])
  {
    opt1=values[n-1]+knapsack(weights , values , n-1 , maxWeight-weights[n-1]);
  }
    opt2=knapsack(weights , values,n-1 , maxWeight);
    return max(opt1 , opt2);
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
  return 0;
}
