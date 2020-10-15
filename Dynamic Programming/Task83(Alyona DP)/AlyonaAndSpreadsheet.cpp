#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=1 ;   i<n+1 ; i++)
    {
        arr[i]=new int[m];
        for(int j=1 ; j<m+1 ; j++)
        {
            cin>>arr[i][j];
        }
    }
    int **dp=new int*[n];
    for(int i=1 ;   i<n+1 ; i++)
    {
        dp[i]=new int[m];
        for(int j=1 ; j<m+1;j++)
            dp[i][j]=0;
    }
    //base case
    for(int j=1 ; j<m+1 ; j++)
    {
        dp[1][j]=1;
    }
    for(int si=2;si<n+1 ; si++)
    {
        for(int sj=1;sj<m+1 ; sj++)
        {
            if( arr[si][sj] >=arr[si-1][sj] )
            {
                dp[si][sj]=dp[si-1][sj];
            }else{
                    dp[si][sj]=si;
                }
        }
    }
    int *mdp=new int[n];
    for(int i=1 ; i<n+1  ; i++)
        mdp[i]=0;
     for(int si=1;si<n+1 ; si++)
    {
        int x=INT_MAX;
        for(int sj=1;sj<m+1 ; sj++)
        {
            x=min(dp[si][sj] ,x);
        }
        mdp[si]=x;
    }
    int query;
    cin>>query;
    while(query--)
    {
        int l,r;
        cin>>l>>r;
        if(   mdp[r]  > l)
        {
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
