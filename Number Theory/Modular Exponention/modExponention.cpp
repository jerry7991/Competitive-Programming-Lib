#include <iostream>
using namespace std;
int modExpo(int a,int b,int c)
{
	if (a==0)
	{
		return 0;
	}
	if (b==0)
	{
		return 1;
	}
	long ans=0;
	if ((b&1))
	{
		//odd
		long smallAns=modExpo(a , b-1 , c);
		ans=((smallAns%c)*(a%c))%c;
	}else{
		//even
		long smallAns=modExpo(a,b/2,c);
		ans=((smallAns%c)*(smallAns%c));
	}
	return (int)((ans+c)%c);
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<modExpo(a, b,c);
	return 0;
}