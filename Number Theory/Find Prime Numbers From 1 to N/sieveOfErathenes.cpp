#include <iostream>
using namespace std;
int countPrime(int n)
{
	bool *sieve=new bool[n+1];
	for (int i = 0; i <=n; ++i)
	{
		sieve[i]=true;
	}
	//according to algo
	sieve[0]=sieve[1]=false;
	for(int p=2 ;p*p<=n ; p++ )
	{
		for(int i=p*p ; i<=n ; i+=p)
		{
			sieve[i]=false;
		}
	}
	int count=0;
	for (int i = 0; i <=n; ++i)
	{
		//cout<<sieve[i]<<" ";
		if (sieve[i])
		{
			count++;
		}
	}
	delete []sieve;
	return count;
}
int main()
{
	int n;
	cin>>n;
	cout<<countPrime(n);
}