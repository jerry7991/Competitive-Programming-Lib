#include <iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2)
{
 int m=s1.size();
 int n=s2.size();
 int **dp=new int*[m+1];
 for (int i = 0; i <=m; ++i)
 {
 	dp[i]=new int[n+1];
 }
 //base case 1:-
 dp[0][0]=0;
 for (int i = 1; i <=m; ++i)
 {
 	dp[i][0]=i;
 }
 for (int i = 0; i <=n; ++i)
 {
 	dp[0][i]=i;
 }
 for (int i = 1; i <=m; ++i)
 {
 	for (int j = 1; j <=n; ++j)
 	{
 		if(s1[m-i]==s2[n-j])
 		{
 			dp[i][j]=dp[i-1][j-1];
 		}else
 		{
 			dp[i][j]=1+min(	dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])	);
 			cout<<dp[i][j]<<endl;
 		}
 	}
 }
 for (int i = 0; i <=m; ++i)
 {
 	for (int j = 0; j <=n; ++j)
 	{
 		cout<<dp[i][j]<<" ";
 	}
 	cout<<endl;
 }
 int answer= dp[m][n];
 for (int i = 0; i <=m; ++i)
 {
 	delete [] dp[i];
 }
 delete []dp;
 return answer;
}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
