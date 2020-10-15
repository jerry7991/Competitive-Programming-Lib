#include <bits/stdc++.h>
#define Max 100001
#define pb(n) push_back(n)
#define ll long long
using namespace std;
vector<int>* seive()
{
	bool *mark=new bool[Max];
	for (int i = 0; i < Max; ++i)
	{
		mark[i]=true;
	}
	mark[0]=mark[1]=false;
	for(int i=2;i*i<Max ; i++)
	{
		if (mark[i])
		{
			for(int j=i*i ; j<Max ; j+=i)
			{
				mark[j]=false;
			}
		}
	}
	vector<int>* _seive=new vector<int>();
	_seive->pb(2);
	for (int i = 3; i <Max ; i+=2)
	{
		if (mark[i])
		{
			_seive->pb(i);
		}
	}
	delete [] mark;
	return _seive;
}
void printPrimes(ll l,ll r,vector<int>* & primes)
{
	int *isPrime=new int[r-l+1];
	for (int i = 0; i < (r-l+1); ++i)
	{
		isPrime[i]=true;
	}
	for (int i = 0; primes->at(i) * (ll) primes->at(i)<=r; ++i)
	{
		int currPrime=primes->at(i);
		//just small or equal value to l
		ll base=(l/currPrime)*currPrime;
		if (base<l)
		{
			base+=currPrime;
		}
		//mark all multiple l to r
		for(ll j=base ; j<=r ; j+=currPrime)
		{
			isPrime[j-l]=false;
		}
		//there may be case where base is itself prime number
		if (base==currPrime)
		{
			isPrime[base-l]=true;
		}
	}
	//print the solution
	for (int i = 0; i <=r-l; ++i)
	{
		if (isPrime[i])
		{
			cout<<i+l<<endl;
		}
	}
	delete [] isPrime;
}
int main()
{
	vector<int> * _seive =seive();
	int t;
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		printPrimes(l,r,_seive);
	}

}