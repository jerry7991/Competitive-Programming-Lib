#include <iostream>
using namespace std;
int moduloExpo(long a , long b , long m)
{
	int ans=1;
	while(b>0)
	{
		if ((b&1))
		{
			//i.e. set bit
			long currAns=a*ans;
			ans=(int)(currAns%m);
		}
		b/=2;
		a=((a%m)*(a%m))%m;
	}
	return ans;
}
int getModFact(long n , long p)
{
	if (n>=p)
	{
		return 0;//becuse n! has at least one element which divide by p
		//i.e. 1*2*3*4*5*.............p*p+1*..........n
	}
	int ans=1;
	for(long i=n+1 ; i<p ; i++)
	{
		long currAns=moduloExpo(i , p-2 , p);
		currAns=ans*currAns;
		ans=(int)(currAns%p);
	}
	return (-ans+p);		//because n! % p=[-1[(((n+1)^p-2)%p)*(((n+2)^p-2)%p)*(((n+3)^p-2)%p)*.....*(((p-1)^p-2)%p)]] which is might be -ve
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		long n,p;
		cin>>n>>p;
		cout<<getModFact(n,p)<<endl;
	}
	return 0;
}