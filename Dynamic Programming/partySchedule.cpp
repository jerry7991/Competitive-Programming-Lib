#include <bits/stdc++.h>
using namespace std;
class two
{
    public:
    int cost;
    int fun;
};
two max(two x,two y)
{
    if(x.fun>y.fun)
        return x;
    else if(x.fun<y.fun)
        return y;
    else
    {
        if(x.cost<y.cost)
            return x;
        else
            return y;
    }
}
two party(int e[],int a[],int n,int b)
{
    if(n==0)
    {
        two p;
        p.cost=0;
        p.fun=0;
        return p;
    }
    if(e[0]>b)
        return party(e+1,a+1,n-1,b);
    two x=party(e+1,a+1,n-1,b-e[0]);
    x.cost+=e[0];
    x.fun+=a[0];
    two y=party(e+1,a+1,n-1,b);
    return max(x,y);
}
int main()
{
    while(1){
    int b,n;
    cin>>b>>n;
        if(b==0&&n==0)
            break;
    int e[n],a[n];
    int i=0;
    for(int i=0;i<n;i++)
    {
        cin>>e[i]>>a[i];
    }
    cout<<party(e,a,n,b).cost<<" "<<party(e,a,n,b).fun<<endl;
    }
    return 0;
}
