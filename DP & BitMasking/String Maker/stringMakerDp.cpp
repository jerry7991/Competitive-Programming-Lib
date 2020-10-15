#include <iostream>
#define fon(i,n) for(int i=0 ; i<n ; i++)
using namespace std;
int dp[51][51][51];
int getAnswer(string a, string b, string c, int l, int m, int n)
{  

   if (n == 0)
   {
      return 1;
   }
   if (l <= 0 && m <= 0)
   {
      return 0;
   }
   //cout << l << " " << m << endl;
   if (dp[l][m][n] != -1)
   {
      return dp[l][m][n];
   }
   
   long int nWay = 0;
   //for a
   for (int k = l - 1; k >= 0; k--)
   {
      if (c[n - 1] == a[k])
      {
         nWay += getAnswer(a, b, c, k, m, n - 1);
         nWay %= mod;
      }
   }
   //for b
   for (int k = m - 1; k >= 0; k--)
   {
      if (c[n - 1] == b[k])
      {
         nWay += getAnswer(a, b, c, l, k, n - 1);
         nWay %= mod;
      }
   }

   dp[l][m][n] = (int)nWay;
   return (int)nWay;
}
int solve(string a, string b, string c)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   fon(i, 51)
   {
      fon(j, 51)
      {
         fon(k, 51)
         {
            dp[i][j][k] = -1;
         }
      }
   }
   int l = a.size(), m = b.size(), n = c.size();
   return getAnswer(a, b, c, l, m, n);
}
int main()
{
 string a,b,c;
 cin>>a>>b>>c;
 cout<<solve(a,b,c)<<endl;
}