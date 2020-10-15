#include <iostream>
#include <string>
using namespace std;
int getCSquare(long a , string b , int m)
{
	int ans=1;
	int len=b.size();
	while(len)
	{
		if (b[len-1]=='1')
		{
			long currAns=(long)ans*a;
			ans=(int)(currAns%m);
		}
		else if (b[len-1]=='2')
		{
			long long currAns=(long long)ans*a*a;
			ans=(int)(currAns%m);
		}
		len--;
		a=((a*a)%m*a)%m;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long a;
		string b;
		int m;
		cin>>a;
		cin>>b;
		cin>>m;
		cout<<getCSquare(a,b,m)<<endl;
	}
}