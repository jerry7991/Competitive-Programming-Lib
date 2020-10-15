#include <istream>
using namespace std;
unsigned int FindPowerModM(unsigned int A, unsigned int B, unsigned int C, unsigned int M){
    int ans=1;
    while(C)
    {
        if((C&1))	ans=((ans%M)*(B%M))%M;
        C/=2;
        B=((B%M)*(B%M))%M;
    }
    int b=ans;
    //cout<<ans<<endl;
    ans=1;
    while(b)
    {
        if((b&1))	ans=((ans%M)*(A%M))%M;
        b/=2;
        A=((A%M)*(A%M))%M;
    }
    return ans;
}
int main()
{
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    cout<<FindPowerModM(a,b,c,m)<<endl;
    return 0;
}