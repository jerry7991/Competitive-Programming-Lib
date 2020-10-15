#include <iostream>
using namespace std;
int solve(long long n)
{
	int count=0;
	while(n)	//O(log n)
	{
		if((n&1))	count++;//i.e. set bits
		n/=2;
	}
	return count;
}
int main()
{
	long long n;
	cin>>n;
	cout<<solve(n);
}