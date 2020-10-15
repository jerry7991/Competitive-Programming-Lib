#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findMinCost(char * bulbStatus ,int len ,ll reverseCost ,ll flipCost)
{
    int zeroGroup=0;
    if(bulbStatus[0]=='0')
        zeroGroup++;
    for(int i=0 ; i<len ; i++)
    {
        if(bulbStatus[i]=='1' && bulbStatus[i+1]=='0')
        {
            zeroGroup++;
        }
    }
    if(zeroGroup==0)
        return 0;
        //cout<<min(reverseCost , flipCost)<<endl;
    //just do operation with zeroGroup member whatever cost is min and at the last we will have to do one flip operation for rest of 0
    return (zeroGroup-1)* min(reverseCost , flipCost)+flipCost ;
}
int main()
{
    int n;
    cin>>n;
    ll reverseCost,flipCost;
    cin>>reverseCost>>flipCost;
    char * bulbStatus = new char[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>*(bulbStatus+i);
    }
    cout<<findMinCost(bulbStatus , n , reverseCost , flipCost);
	return 0;
}

