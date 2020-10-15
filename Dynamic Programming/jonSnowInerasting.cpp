#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ;i++)
using namespace std;
int main()
{
  int n,k,x,nMax=1024;
  cin>>n>>k>>x;
  int **freq=new int*[2];
  freq[0]=new int[nMax];
  freq[1]=new int[nMax];
  fon(i,nMax) freq[0][i]=freq[1][i]=0;
  fon(i,n)
  {
    int p;cin>>p;
    freq[0][p]++;
    freq[1][p]++;
  }
  int flag=0;
  while (k--) {
    int curr=0;
    fon(i,nMax)
    {
      int f=freq[flag][i];
      if(!f) continue;
       f=(freq[flag][i]+((curr%2)^1))/2;
      freq[flag^1][(i^x)]+=f;
      freq[flag^1][i]-=f;
      curr+=freq[flag][i];
    }
    flag^=1;
  }
  for(int i=nMax-1;i>=0 ; i--)
    if(freq[flag][i]>0)
    {
      cout<<i<<" ";
      break;
    }
  fon(i , 20)
    if(freq[flag][i]>0)
      {
        cout<<i;
        break;
      }
}
