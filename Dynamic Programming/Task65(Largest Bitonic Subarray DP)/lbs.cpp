#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define forn(i,n) for (lli i = 0; i < lli(n); ++i)
int longestBitonicSubarray(int *input, int n)
{
    vector<int>vect;
    int dp1[n],dp2[n];
        for(int i=0;i<n;i++)
        {
            vect.push_back(input[i]);
        }
        for(int i=0;i<n;i++)
        {
            dp1[i]=1;
            dp2[i]=1;
        }
        for(int i=1;i<n;i++)
       {
           int k=0;
           for(int j=i-1;j>=0;j--)
           {
               if(vect[i]>vect[j]){
                   if(dp1[j]>k)
                       k=dp1[j];
               }
           }
           dp1[i]=k+1;
       }
       reverse(vect.begin(),vect.end());
       for(int i=1;i<n;i++)
       {
           int k=0;
           for(int j=i-1;j>=0;j--)
           {
               if(vect[i]>vect[j]){
                    if(dp2[j]>k)
                        k=dp2[j];
               }
           }
           dp2[i]=k+1;
       }
       for(int j=0,k=n-1;j<n/2;j++,k--)
       {
           swap(dp2[j],dp2[k]);
       }
       lli maxz=INT_MIN;
        forn(i,n){
            int s=dp1[i]+dp2[i]-1;
            if(s>maxz)
            maxz=s;
        }
        return maxz;
}
int main()
{
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  //cout<<longestBitonicSubarray(input, n);
  return 0;
}
//  1111111111111101
// +0000000000000101
// -------------------
//  0000000000000000
//  ----------------
//  since we have a carry so have to add carry with 1's compliment
//  carry 1 once compliment 1111111111110
//   0000000000010
// + 1111111111110
// -------------------
//  00000000000000
//  ----------------