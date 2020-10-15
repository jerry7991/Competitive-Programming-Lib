#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int LBS(int *arr , int n)
{
  //we need to find longest increasing and dec till i-th points
  int *preInc=new int[n];
  int *suffDec=new int[n];
  for (size_t i = 0; i < n; i++) {
    preInc[i]=suffDec[i]=1;
  }
  //let's find the longest increasing subsquence
  for(int i=1;i<n ; i++)
  {
    fon(j,i)
    {
      if(arr[i]>arr[j] && (preInc[i]<preInc[j]+1))
      {
        preInc[i]=preInc[j]+1;
      }
    }
  }
  //let's find longest decreasing subsquence from end
  for(int i=n-2;i>=0;i--)
  {
    for(int j=n-1 ; j>i;j--)
    {
      if(arr[i]>arr[j] && (suffDec[i]<(suffDec[j]+1)))
      {
        suffDec[i]=suffDec[j]+1;
      }
    }
  }
  int maxF=0;
  for(int i=0 ; i<n ; i++)
  {
    maxF=max(maxF,preInc[i]+suffDec[i]-1);
  }
  return maxF;
}
int main()
{
  int n;cin>>n;
  int *arr=new int[n];
  for(int i=0  ; i<n ; i++)
  {
    cin>>arr[i];
  }
  cout<<LBS(arr , n);
  return 0;
}
