#include<bits/stdc++.h>
using namespace std;
int memo[101][101][2];
int n,k;
int mod=pow(10,9)+7;
void init()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<2;k++)
                memo[i][j][k]=-1;
}
int dp(int index,int current_k,int prev_bit)
{
    if(index==n)
        return current_k==k;
    int &ret=memo[index][current_k][prev_bit];
    if(ret==-1)
    {

        ret=dp(index+1,current_k+prev_bit,1);
        ret=(ret+dp(index+1,current_k,0))%mod;
    }
    return ret;
}
int main()
{
    int test;
    int data_set_number;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&data_set_number,&n,&k);
        init();
        int ans=dp(0,0,0);
         printf("%d %d\n",data_set_number,ans);
    }
return 0;
}
