#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define nMax 1024
using namespace std;
int main()
{
  int n,k,x;
  cin>>n>>k>>x;
  int *freq=new int[nMax];
  fon(i,nMax) freq[i]=0;
  fon(i,n)
  {
    int p;cin>>p;
    freq[p]++;
  }
  int curr=0;
  int *out=new int[nMax];
  fon(i,nMax) out[i]=freq[i];
  while (k--) {
    curr=0;
    fon(i,nMax)
    {
      if(freq[i]==0)  continue;
      int f;
      if(curr%2==0)
      {
        f=(freq[i]+1)/2;
      }else{
        f=freq[i]/2;
      }
      int index=i^x;
      out[index]+=f;
      out[i]-=f;
      curr+=freq[i];
    }
    //now have to copy
    fon(j,nMax) freq[j]=out[j];
  }
  for(int i=nMax-1 ; i>=0 ; i--)
  {
    if(freq[i])
    {
      cout<<i<<" ";
      break;
    }
  }
  fon(i,nMax)
  {
    if(freq[i])
    {
      cout<<i;
      break;
    }
  }
}
