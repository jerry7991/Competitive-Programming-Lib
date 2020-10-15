#include <iostream>
using namespace std;
int modExpo(int a,int b,int c)
{
	int ans=1;
	while(b!=0)
	{
		if ((b&1))
		{
			ans=(ans*a)%c;
		}
		b/=2;
		a=((a%c)*(a%c))%c;
	}
	return ans;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<modExpo(a,b,c);
	return 0;
}