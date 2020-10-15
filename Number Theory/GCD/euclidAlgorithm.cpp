#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	if (a<b)
	{
		//need to swap
		return gcd(b,a);
	}
	if (b==0)
	{
		return a;
	}
	//Answer applied Euclide algorithms
	return gcd(b , a%b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}