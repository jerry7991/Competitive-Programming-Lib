#include<bits/stdc++.h>
using namespace std;
int findMaxAverage(int arr[], int n, int k)
{
    // Check if 'k' is valid
    if (k > n)
        return -1;

    // Compute sum of first 'k' elements
    int sum = arr[0];
    for (int i=1; i<k; i++)
        sum += arr[i];

    int max_sum = sum, max_end = k-1;

    // Compute sum of remaining subarrays
    for (int i=k; i<n; i++)
    {
        int sum = sum + arr[i] - arr[i-k];
        if (sum > max_sum)
        {
            max_sum = sum;
            max_end = i;
        }
    }

    // Return starting index
    return max_end - k + 1;
}
int main() {

  int n,k;
  cin>>n>>k;
  int *arr=new int[n];
  for(int i=0 ; i<n ; i++)  cin>>arr[i];
  int x=findMaxAverage(arr , n , k);
  double sum=0.0;
  for(int i=x ; i<x+k ; i++)  sum+=arr[i];
  cout<< fixed << setprecision(6) <<double(sum/k);
}
