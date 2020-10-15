#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPossibleK(ll totalBalls , ll k)
{
    ll sum=0;
    ll curr=totalBalls;
    while(curr >0 )
    {
        sum = sum+ min(curr , k);
        curr = curr-k;//sharma ji took the balls
        curr=curr-curr/10;//singh ji took the ball
    }
    if(sum*2 >=totalBalls)
        return true;
    return false;
}
int main()
{
    ll totalBalls;
    cin>>totalBalls;

    ll start=1;//min 1 is possible
    ll end=totalBalls;
    ll k=1;
    while(start <= end)
    {
        ll mid=(start+end)/2;
        //cout<<mid<<endl;
       if(isPossibleK(totalBalls , mid))
       {
           ///mean of mid it give so we will have to found min k
           //k=min(mid , k);
           k=mid;
           end=mid-1;
       }else{
            //we found  2*k<sum so search for right
            start=mid+1;
       }
    }
    cout<<k;
    return 0;
}
