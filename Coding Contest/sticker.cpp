#include <iostream>
#include<algorithm>
#define ll unsigned long long int
using namespace std;
ll solve(ll *arr , int n , ll k ,ll m)
{
  sort(arr , arr+n , greater<int>());
  ll ans=0;
  int times=0;
  while (m--) {
    if(times==k)
    {
      ans+=arr[1];
      times=0;
    }else{
      ans+=arr[0];
      times++;
    }
  }
  return ans;
}
int main()
{
  int n;
  ll k,m;
  cin>>n>>m>>k;
  ll *arr=new ll[n];
  for(int i=0 ; i<n ; i++)
  {
    cin>>arr[i];
  }
  cout<<solve(arr , n , k , m);
}
