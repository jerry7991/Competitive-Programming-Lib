#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int main()
{
  int n;
  cin>>n;
  int *starting=new int[n];
  int *ending=new int[n];
  fon(i,n)  starting[i]=ending[i]=0;
  int nQuery;
  cin>>nQuery;
  while (nQuery--) {
    int l,r;
    cin>>l>>r;
    starting[l-1]++;ending[r-1]++;
  }
  int *sum=new int[n];sum[0]=starting[0];
  int maxV=0;
  for(int i=1;i<n;i++)
    sum[i]=starting[i]-ending[i-1]+sum[i-1] ;
  fon(i,n) maxV=max(sum[i] , maxV);
  int *output=new int[maxV+1];
  fon(i,maxV+1)  output[i]=0;
  fon(i ,n) output[sum[i]-1]++;
  for(int i=maxV-1;i>=0 ; i--)  output[i]+=output[i+1];
  fon(i,maxV+1) cout<<output[i]<<endl;
  delete []sum;
  delete []starting;
  delete []ending;
  cin>>nQuery;
  while (nQuery--) {
    int x;
    cin>>x;
    if(x<=maxV) std::cout << output[x-1] << '\n';
    else std::cout << 0 << '\n';
  }
  delete []output;
  return 0;
}
