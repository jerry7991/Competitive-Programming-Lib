#include<iostream>
#include<cmath>
using namespace std;

// Function to find number of unique BST
int numberOfBST(int n)
{

    // DP to store the number of unique BST with key i
    int dp[n + 1];
    fill_n(dp, n + 1, 0);
    // Base case
    dp[0] = 1;
    dp[1] = 1;
    int m=pow(10,9)+7;
    // fill the dp table in top-down approach.
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // n-i in right * i-1 in left
            long ans=(long)dp[i - j] * dp[j - 1];
            int ans1=(int)(ans%m);
            dp[i] = (dp[i] +ans1)%m ;
        }
    }

    return dp[n];
}
int main()
{
    int number;
    cin>>number;
    cout<<numberOfBST(number)<<endl;
}
