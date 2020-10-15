#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll insertBitIntoNumber(ll n , ll m , int i , int j)
{
    ll allOnce= ~0;
    ll left = allOnce << (j+1);//make space for j
    ll right = ((1<<i)-1);

    ll mask= left | right;
     //let's clear from j through i
     ll n_cleared= n & mask;

     //move m to i
     ll m_moved= m<<i;
     return n_cleared | m_moved;
}
int main()
{
    ll n , m ;
    int  i , j;
    cin>>n>>m>>i>>j;
    cout<<insertBitIntoNumber(n , m , i , j);
    return 0;
}
