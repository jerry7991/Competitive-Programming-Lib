#include <iostream>
#include <vector>
#define ll long long
#define nMax 1000001
#define pb(n) push_back(n)
using namespace std;
void seive(vector<int> &prime)
{
	bool *mark=new bool[nMax];
	for(int i=0 ; i<nMax ;i++) mark[i]=true;
	mark[0]=mark[1]=false;

	for(int i=2; i*i<nMax ; i++)
	{
		if (mark[i])
		{
			prime.pb(i);
			for(int j=i*i ;j<nMax ; j+=i) mark[j]=false;
		}
	}
	delete [] mark;
}
void EulerTotient(int *phi ,ll n)
{
	for(ll i=1 ; i<=n  ; i++)	*(phi+i)=i;

	for(ll i=2 ; i<=n ; i++)
	{
		if (phi[i]==i)
		{
			phi[i]=i-1;
			for(ll j=2*i ; j<=n ; j+=i)	phi[j]=(phi[j]*(i-1))/i;
		}
	}
}
void func(ll n)
{
	vector<int> prime;
	seive(prime);
	vector<int>divisor;
	ll x=n , i=0;
	while(x>1)
	{
		if(x%prime[i]==0)
		{
			divisor.pb(prime[i]);
			while(x%prime[i]==0)	x/=prime[i];
		}
		i++;
	}
	int *phi=new int[n];
	EulerTotient(phi , n);
	ll lcmSUM=0;
	for(unsigned int i=0 ; i<divisor.size();i++)
	{
		lcmSUM+=(phi[divisor[i]]*divisor[i]);
	}
	lcmSUM=((1+lcmSUM)*n);
	cout<<lcmSUM<<endl;
}
int main()
{ 
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}
