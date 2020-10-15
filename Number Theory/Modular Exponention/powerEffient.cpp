#include <iostream>
using namespace std;
int power(int a , int b)
{
	if (b==0)
	{
		return 1;
	}
	if (a==0)
	{
		return 0;
	}
	if (b%2==0)
	{
		int ans=power(a,b/2);
		ans=ans*ans;
		return ans;
	}else{
		int ans=power(a,b-1);
		ans=ans*a;
		return ans;
	}
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<power(a,b);
}