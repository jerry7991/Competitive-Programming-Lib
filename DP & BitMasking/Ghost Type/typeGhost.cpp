#include <iostream>
using namespace std;

long long  solve(int N)
{   long long  *dp=new long long[1<<N]; 
	for(int i=0;i<(1<<N);i++){
        dp[i]=0;
    }
   dp[0]=1;
 
 for(int mask=0;mask<((1<<N)-1);mask++){
    
     for(int j=0;j<N;j++){
         if(!(mask&(1<<j)) ){
             int flag=1;
             for(int i=0;i<N;i++){
                if((mask&(1<<i)) and (((i+1)&(j+1))==(j+1))){
                    flag=0;
                    break;
                } 
             }
             if(flag==1)
             dp[mask|(1<<j)]+=dp[mask];
         }
     }
    }
 return dp[(1<<N)-1];
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}