#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int n,k,*arr;
bool isSubSet(int x=k , int N=n)
{
  if(N==0 || x<0) return x==0;
  if(x==0)  return true;
  bool ans1=false , ans2=false;
  if(x>=arr[N-1])
    ans1=isSubSet(x-arr[N-1] , N-1);
  ans2=isSubSet(x,N-1);
  return ans1||ans2;
}
int main()
{
  cin>>n;
  arr=new int[n];
  fon(i,n)cin>>arr[i];
  cin>>k;
  bool ans=isSubSet();
  if(ans) cout<<"Yes";
  else cout<<"No";
  return 0;
}
