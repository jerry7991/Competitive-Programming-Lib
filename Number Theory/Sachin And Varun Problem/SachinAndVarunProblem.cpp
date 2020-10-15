#include <iostream>
#define ll long long
using namespace std;
class Triplet
{
public:
	ll gcd;
	ll x;
	ll y;
};
Triplet gcdExtendedEuclid(ll a , ll b)
{
	//base case
	if (b==0)
	{
		//ax+by=gcd(a,b);
		//b=0-> y=0 ; x=1 , gcd(a,b)=a;
		Triplet ans;
		ans.x=1;
		ans.y=0;
		ans.gcd=a;
		return ans;
	}
	Triplet smallAns=gcdExtendedEuclid(b , a%b);
	Triplet myAns;
	myAns.gcd=smallAns.gcd;
	myAns.x=smallAns.y;
	myAns.y=(smallAns.x)-((a/b)*(smallAns.y));
	return myAns;
}
ll modInverse(ll a , ll m)
{
	ll x=gcdExtendedEuclid(a,m).x;
	return (x%m+m)%m;
}
ll gcd(int a,int b)
{
	if (b==0)
	{
		return a;
	}
	if (a<b)
	{
		return gcd(b,a);
	}
	return gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,d;
		cin>>a>>b>>d;

		ll g=gcd(a,b);
		if (d%g)
		{
			cout<<0<<endl;
			continue;
		}
		if (d==0)
		{
			cout<<1<<endl;
            continue;
		}
		a/=g,b/=g,d/=g;//just for optimize

		ll y1=((d%a)*modInverse(b,a))%a;

		ll firstValue=d/b;
		if (d<(y1*b))
		{
			cout<<0<<endl;
			continue;
		}

		ll n=(firstValue-y1)/a;
		ll ans=n+1;
		cout<<ans<<endl;
	}
}