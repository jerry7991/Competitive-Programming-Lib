#include <iostream>
#include<algorithm>
using namespace std;
bool getAnswer(int *arr , int  n , int x)
{
  int nEven=0,nOdd=0;
  for (size_t i = 0; i < n; i++) {
    if((arr[i]&1))
      nEven++;
    else
      nOdd++;
  }
  if(nOdd==0)
    return false;
  else if()
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    cin>>n>>x;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    if(getAnswer(arr , n , x))
    {
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
