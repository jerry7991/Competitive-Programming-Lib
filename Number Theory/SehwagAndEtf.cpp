#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
typedef long long ll;
vector<int>* sieve()
{
	bool isPrime[MAX];
	for (int i = 0; i < MAX; i++)
		isPrime[i] = true;
	for (int i = 2; i * i < MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	vector<int>* primes = new vector<int>();
	primes->push_back(2);
	for (int i = 3; i < MAX; i += 2)
	{
		if (isPrime[i]) primes->push_back(i);
	}
	return primes;
}
int getPhi(long long l, long long r, long long k, vector<int>* & primes)
{
	ll phi[r - l + 1];
	ll arr2[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		phi[i - l] = i; arr2[i - l] = i;
	}
	for (int i = 0; (primes->at(i) * (long long)(primes->at(i))) <= r; i++)
	{
		int currentPrime = primes->at(i);
		long long base = (l / currentPrime) * currentPrime;
		if (base < l) {
			base += currentPrime;
		}
		if (base == currentPrime) base = base + currentPrime;
		for (ll j = base; j <= r; j += currentPrime)
		{
			phi[j - l] = (phi[j - l] * (currentPrime - 1)) / currentPrime;
			while (arr2[j - l] % currentPrime == 0)
			{
				arr2[j - l] = arr2[j - l] / currentPrime;
			}
		}
	}
	for (ll j = l; j <= r; j++)
	{
		if (arr2[j - l] > 1) phi[j - l] = ( phi[j - l] * (arr2[j - l] - 1) ) / arr2[j - l];
	}
	int count = 0;
	for (ll j = l; j <= r; j++)
	{
		if ((phi[j - l] % k) == 0) count++;
	}
	return count;
}
int main()
{
	vector<int>* primes = sieve();
	int t; cin >> t;
	while (t--)
	{
		long long l, r, k;
		cin >> l >> r >> k;
		int count = getPhi(l, r, k, primes);
		double prob = (count * 1.0) / (r - l + 1);
		std::cout << std::setprecision(6) << std::fixed; cout << prob << endl;
	}
	return 0;
}