#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 1000000;

// Returns count of distinct subsequences of str. 
long long countSub(string str)
{ long long md=1000000000+7;
	// Create an array to store index
	// of last
	vector<long long> last(500, 0);

	// Length of input string
	long long n = str.length();

	// dp[i] is going to store count of distinct
	// subsequences of length i.
	long long dp[n + 1];
    for(int i=0;i<=n;i++)
        dp[i]=0;
	// Empty substring has only one subsequence
	dp[0] = 1;
        for(int i = 1 ; i<= n ; i++){
            dp[i] = (dp[i-1] * 2)%md;
            if(last[str[i-1]]!=0 )
                dp[i] = (dp[i]%md - dp[last[str[i-1]] - 1]%md + md)%md;
            last[str[i-1]] = i;
        }
        return dp[n];
}

// Driver code
int main()
{ int t;
 int mod= 1000000000+7;
 cin>>t;
 while(t--)
 { string s;
  cin>>s;
	cout << countSub(s)%mod<<"\n";
 }
	return 0;
}
