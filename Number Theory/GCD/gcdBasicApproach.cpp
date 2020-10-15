#include <iostream>
using namespace std;
int gcd(int a , int b)
{
	//min gcd is 1
	int g=1,gc_d=1;
	while(g<a && g<b)
	{
		if (a%g==0 && b%g==0)
		{
			gc_d=g;
		}
		g++;
	}
	return g;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}