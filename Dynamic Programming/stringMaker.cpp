#include <iostream>
#include <string>
using namespace std;
int nWay(string a , string b , string c , int l,int m , int n)
{
	if (n<0)
	{
		return 1;
	}
	char ch=c[n];
	int ans=0;
	//let's find the occurance of ch in a and count the number of ways to make string with that point
	for(int i=l ;i>=0;i--)
	{
		if(a[i]==ch)
		{
			ans+=nWay(a,b,c,i-1,m,n-1);
		}
	}
	//let's find the occurane of ch in b and count the number of ways to make string with that point
	for(int i=m;i>=0 ; i--)
	{
		if(b[i]==ch)
		{
			ans+=nWay(a,b,c,l,i-1,n-1);
		}
	}
	return ans;
}
int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<nWay(a,b,c , a.length()-1 , b.length()-1 ,c.length()-1 );
}