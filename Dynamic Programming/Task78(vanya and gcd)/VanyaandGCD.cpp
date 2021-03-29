#include<bits/stdc++.h>
using namespace std;
int _gcd(int a , int b)
{
    if (b == 0)
    return a;
return _gcd(b, a % b);

}
int find_IS_GCD1(int *arr ,int n)
{
    int mod=pow(10,9)+7;
    int **dp_gcd=new int*[n];
   for(int i=0 ; i<n ; i++)
    {
        dp_gcd[i]=new int[100];

        for(int j=0;j<100;j++)
            dp_gcd[i][j]=0;

        dp_gcd[i][arr[i]]=1;
    }
    //let's store gcd
    // for(int i=1 ; i<n ; i++)
    // {
    //     int new_gcd=    _gcd(arr[i-1] ,arr[i]);
    //     dp_gcd[i][new_gcd]++;
    // }
    for(int i=0 ; i<n ; i++)
    {
        for(int k=i-1 ; k>=0 ; k--)
        {
            if(arr[k]<arr[i])
            {
            for(int g=0 ; g<100;g++)
            {
                
                   int new_gcd= _gcd(arr[i] , g);
                   dp_gcd[i][new_gcd]     =   (    dp_gcd[i][new_gcd]+dp_gcd[k][g]    )%mod;
            
            }
            }
        }
    }
    int sq=0;
    for(int i=0 ; i<n;i++)
    {
        sq  =(sq+dp_gcd[i][1])%mod;
    }
    return sq;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0 ; i<n ;i++)
    {
        cin>>*(arr+i);
    }
    cout<<find_IS_GCD1(arr , n);
}

